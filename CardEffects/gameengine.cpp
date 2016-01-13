#include "gameengine.h"

// Constructor
GameEngine::GameEngine()
{}

// Destructor
GameEngine::~GameEngine()
{}

// ---------------------------
// METHODS
// ---------------------------

// Execute an action
QString GameEngine::ExecuteAction(Action action) {

    // Final return string
    QString resultString;

    // Extract the fields of action

    // Carry out procedures

    // DEBUGGING
    resultString.append("Successully executed command: ");
    resultString.append(action.GetStringCommand());

    return resultString;
}

