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
            QString resultString;
            resultString += "Error: No parameters given for the command '" + commandString + "'.";
            return resultString;
        }

        if (CheckParameters(commandString, commandComponents)) {

            // Command is valid - create the action, and
            // return the result from GameEngine
            Action * action = new Action();
            action->SetStringCommand(command);

            // ToDo: Fill out the appropriate fields in the Action object

            return gameEngine->ExecuteAction(action);
        } else {

            // At least one of the parameters are invalid
            QString resultString;
            resultString.append("Error: Incorrect parameter(s) for command '");
            resultString.append(commandString);
            resultString.append("'.");
            return resultString;
        }
    } else {

        // Invalid command: return error string
        // Todo: Suggest a correction to the command
        QString resultString;
        resultString.append("Error: The command '");
        resultString.append(commandComponents.first());
        resultString.append("' is not found. Check for any spelling errors.");
        return resultString;
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
    summonParameters->append(QRegExp(this->VALID_CARD_REGEX));
    summonParameters->append(QRegExp(this->VALID_POSITION_REGEX));
    this->commandFormatMap->insert(summonCommandStr, *summonParameters);
}

// Checks whether the input command is a valid command
// ie one of the keys in the mapping
bool CommandParser::CheckCommand(QString command) {
    return this->commandFormatMap->keys().contains(command);
}

// Checks whether the given parameters to a command (all stored in a QStringList) are valid
bool CommandParser::CheckParameters(QString command, QStringList parameters) {


    // Todo: Determine what type of parameters are associated with the command
    QVector<QRegExp> acceptedParameters = this->commandFormatMap->value(command).toVector();
    QVector<QString> givenParameters = parameters.toVector();

    // Loop through each mapped parameter, and check the same parameter given matches the regex
    for (int i = 0; i < acceptedParameters.size(); i++) {
        if (!givenParameters[i].contains(acceptedParameters[i])) {
            return false;
        }
    }

    // At this point, all parameters have been confirmed to match the regex corresponding to the command
    return true;

}

