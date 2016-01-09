#include "commandparser.h"


// Constructor
CommandParser::CommandParser()
{
    // Set up the list of valid commands
    InitialiseCommandMapping();
}

// Destructor
CommandParser::~CommandParser()
{
}

// ---------------------
// METHODS
// ---------------------

// Attach a GameEngine
void CommandParser::SetGameEngine(GameEngine * newGameEngine) {
    gameEngine = newGameEngine;
}

// Decrypt the meaning of a user-entered command
QString CommandParser::ParseCommand(QString command) {

    // Check if there is an existing game
    if (gameEngine == 0) {      //null gameEngine
        return QString("Command not accepted: Please start a new game.");
    }

    // Transform all characers in command to lower case
    QString lowerCommand = command.toLower();

    // Break down the command into its components, and check (in succession) their validity
    QStringList commandComponents = lowerCommand.split(QChar(' '));

    // Check the command
    QString commandString = commandComponents.first();
    if (CheckCommand(commandString)) {

        // Check the parameters
        commandComponents.removeFirst();    //remove the command (leaving only parameters)

        // case when no parameters are supplied to a command that accepts parameters
        if (commandComponents.size() == 0 &&  this->commandFormatMap->value(commandString).size() != 0) {
            return BuildNoParameterErrorString(commandString);
        }

        int incorrectParameter = CheckParameters(commandString, commandComponents);
        QVector<QString> commandComponentsVector = commandComponents.toVector();
        if (incorrectParameter == this->ALL_PARAMETERS_VALID) {

            // Command is valid - create the action, and
            // return the result from GameEngine
            Action * action = new Action();
            action->SetStringCommand(command);

            // ToDo: Fill out the appropriate fields in the Action object

            return gameEngine->ExecuteAction(action);
        } else {

            // At least one of the parameters are invalid
            // Return the appropriate error message
            // Note: assume incorrectParameter is >= 0 at this point
            return BuildParameterErrorString(incorrectParameter+1, commandComponentsVector[incorrectParameter]);
        }
    } else {

        // Invalid command: return error string
        // Todo: Suggest a correction
        return BuildCommandErrorString(commandComponents.first());

    }

}

// ------------------
// PRIVATE FUNCTIONS
// ------------------

void CommandParser::InitialiseCommandMapping() {
    this->commandFormatMap = new QMap<QString, QList<QRegExp> >();

    // Summon command: valid card name, (position)
    QString summonCommandStr = "summon";
    QList<QRegExp> * summonParameters = new QList<QRegExp>();
    summonParameters->append(QRegExp(QString("^" + this->VALID_CARD_REGEX + "$"))); //append the anchors to the standard defined regex
    summonParameters->append(QRegExp(QString("^" + this->VALID_POSITION_REGEX + "$")));
    this->commandFormatMap->insert(summonCommandStr, *summonParameters);

    // Activate command: valid card name
    QString activateCommandStr = "activate";
    QList<QRegExp> * activateParameters = new QList<QRegExp>();
    activateParameters->append(QRegExp(QString("^" + this->VALID_CARD_REGEX + "$")));
    this->commandFormatMap->insert(activateCommandStr, *activateParameters);


}

// Checks whether the input command is a valid command
// ie one of the keys in the mapping
bool CommandParser::CheckCommand(QString command) {
    return this->commandFormatMap->keys().contains(command);
}

// Checks whether the given parameters to a command (all stored in a QStringList) are valid
int CommandParser::CheckParameters(QString command, QStringList parameters) {


    // Todo: Determine what type of parameters are associated with the command
    QVector<QRegExp> acceptedParameters = this->commandFormatMap->value(command).toVector();
    QVector<QString> givenParameters = parameters.toVector();

    // Loop through each mapped parameter, and check the same parameter given matches the regex
    for (int i = 0; i < givenParameters.size(); i++) {
        if (!givenParameters[i].contains(acceptedParameters[i])) {
            return i;
        }
    }

    // At this point, all parameters have been confirmed to match the regex corresponding to the command
    return this->ALL_PARAMETERS_VALID;

}

// -------------------------------
// ERROR STRING BUILDING FUNCTIONS
// -------------------------------

// Build the appropriate error string for when a command is incorrect
QString CommandParser::BuildCommandErrorString(QString command) {
    QString resultString;
    resultString.append("Error: The command '");
    resultString.append(command);
    resultString.append("' is not found. Check for any spelling errors.");
    return resultString;
}

// Build the appropriate error string for when a parameter is incorrect
QString CommandParser::BuildParameterErrorString(int parameterPosition, QString parameterValue) {
    QString resultString;
    resultString.append("Error: Parameter ");
    resultString.append(QString::number(parameterPosition));       // incorrectParameter is index based
    resultString.append(" ('");
    resultString.append(parameterValue);
    resultString.append("') is incorrect.");
    return resultString;
}

// Build the appropriate error string for when no parameters are supplied for a command
// that takes in at least 1 parameter
QString CommandParser::BuildNoParameterErrorString(QString command) {
    QString resultString;
    resultString += "Error: No parameters given for the command '" + command + "'.";
    return resultString;
}
