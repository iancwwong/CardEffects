#include "commandparser.h"


// Constructor
CommandParser::CommandParser()
{
    // Set up the list of valid commands
    this->commandList = new QStringList();
    this->commandList->append("summon");
    this->commandList->append("activate");
    this->commandList->append("attack");
    this->commandList->append("goto");
    this->commandList->append("view");
    this->commandList->append("info");
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

    // Break down the command into its components, and check (in succession) their validity
    QStringList commandComponents = command.split(QChar(' '));

    // Check the command
    QString commandString = commandComponents.first();
    if (CheckCommand(commandString)) {

        // Check the parameters
        if (CheckParameters(commandComponents)) {

            // Command is valid - create the action, and
            // return the result from GameEngine
            Action * action = new Action(command);

            // ToDo: Fill out the appropriate fields in the Action object

            return gameEngine->ExecuteAction(action);
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

// Checks whether the input command is a valid command
bool CommandParser::CheckCommand(QString command) {
    return this->commandList->contains(command,Qt::CaseInsensitive);
}

// Checks whether the given parameters to a command (all stored in a QStringList) are valid
bool CommandParser::CheckParameters(QStringList commandComponents) {
    QString command = commandComponents.first();

    // Todo: Determine what type of parameters are associated with the command

    return true;

}

