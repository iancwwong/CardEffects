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

        // case when insufficient arguments have been supplied
        if (commandComponents.size() != this->commandFormatMap->value(commandString).size()) {
            return BuildInsuffParameterErrorString(commandString);
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

    // For regex's made out of other regex's
    QStringList * builtRegexList;
    QString builtRegex;

    // Summon command: valid card name, (position)
    QString summonCommandStr = "summon";
    QList<QRegExp> * summonParameters = new QList<QRegExp>();
    summonParameters->append(QRegExp(QString("^" + this->VALID_CARD_REGEX + "$"))); //append the anchors to the standard defined regex
    this->commandFormatMap->insert(summonCommandStr, *summonParameters);

    // Activate command: valid card name
    QString activateCommandStr = "activate";
    QList<QRegExp> * activateParameters = new QList<QRegExp>();
    activateParameters->append(QRegExp(QString("^" + this->VALID_CARD_REGEX + "$")));
    this->commandFormatMap->insert(activateCommandStr, *activateParameters);

    // Attack comand: valid card name, valid card name / shield / direct
    QString attackCommandStr = "attack";
    QList<QRegExp> * attackParameters = new QList<QRegExp>();
    attackParameters->append(QRegExp(QString("^" + this->VALID_CARD_REGEX + "$")));
    builtRegexList = new QStringList();     // Attack command second parameter
    builtRegexList->append(this->VALID_CARD_REGEX);
    builtRegexList->append("shield");
    builtRegexList->append("direct");
    builtRegex = BuildRegex(*builtRegexList);
    attackParameters->append(QRegExp(QString("^" + builtRegex + "$")));
    this->commandFormatMap->insert(attackCommandStr, *attackParameters);

    // Goto command: phase name
    QString gotoCommandStr = "goto";
    QList<QRegExp> * gotoParameters = new QList<QRegExp>();
    builtRegexList = new QStringList();
    builtRegexList->append("mp1");  // main phase 1
    builtRegexList->append("bp");   // battle phase
    builtRegexList->append("mp2");  // main phase 2
    builtRegexList->append("end");  // end
    builtRegex = BuildRegex(*builtRegexList);
    gotoParameters->append(QRegExp(QString("^" + builtRegex + "$")));
    this->commandFormatMap->insert(gotoCommandStr, *gotoParameters);

    // View command: playing area
    QString viewCommandStr = "view";
    QList<QRegExp> * viewParameters = new QList<QRegExp>();
    builtRegexList = new QStringList();
    builtRegexList->append("hand");
    builtRegexList->append("grave");
    builtRegexList->append("battlefield");
    builtRegexList->append("shields");
    builtRegex = BuildRegex(*builtRegexList);
    viewParameters->append(QRegExp(QString("^" + builtRegex + "$")));
    this->commandFormatMap->insert(viewCommandStr, *viewParameters);

    // Info command: game attribute
    QString infoCommandStr = "info";
    QList<QRegExp> * infoParameters = new QList<QRegExp>();
    builtRegexList = new QStringList();
    builtRegexList->append("phase");
    builtRegex = BuildRegex(*builtRegexList);
    infoParameters->append(QRegExp(QString("^" + builtRegex + "$")));
    this->commandFormatMap->insert(infoCommandStr, *infoParameters);

}

// Checks whether the input command is a valid command
// ie one of the keys in the mapping
bool CommandParser::CheckCommand(QString command) {
    return this->commandFormatMap->keys().contains(command);
}

// Checks whether the given parameters to a command (all stored in a QStringList) are valid
int CommandParser::CheckParameters(QString command, QStringList parameters) {

    QVector<QRegExp> acceptedParameters = this->commandFormatMap->value(command).toVector();
    QVector<QString> givenParameters = parameters.toVector();

    // Remove any given parameters that are extra
    while (givenParameters.size() > acceptedParameters.size()) {
        givenParameters.removeLast();
    }

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

QString CommandParser::BuildInsuffParameterErrorString(QString command) {
    int numAcceptedParameters = this->commandFormatMap->value(command).size();
    QString resultString = "Error: '" + command + "' takes "
                           + QString::number(numAcceptedParameters) + " parameters.";
    return resultString;
}

// -------------------------------
// OTHER FUNCTIONS
// -------------------------------

// Appends a bunch of strings into one string to be used as a regex
// NOTE: Assumes each of the strings are valid regex expressions
//       and that stringList has at least two items
// Basically wraps each string in '()', and concatenates them with '|'
QString CommandParser::BuildRegex(QStringList stringList) {

    QString finalRegexString;

    QVector<QString> stringVector = stringList.toVector();
    for (int i = 0; i < stringVector.size(); i++) {
        QString tempRegex = "(" + stringVector[i] + ")";

        // Append the '|' ONLY if current string is not the last
        if (i < stringVector.size() - 1) {

            tempRegex.append("|");
        }

        // Add to the final string
        finalRegexString.append(tempRegex);
    }

    return finalRegexString;
}
