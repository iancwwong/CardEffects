#include "commandparser.h"


// Constructor
CommandParser::CommandParser()
{
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

    // final return string containing the result
    QString resultString;

    // Parse the command and test its validity
    bool commandValid = true;

    // Determine whether to pass as an action
    if (commandValid) {
        // Create the action
        Action * action = new Action(command);

        // Execute action using GameEngine
        resultString = gameEngine->ExecuteAction(action);

    } else {
        resultString = "Invalid command. Please try again.";
    }

    return resultString;
}

