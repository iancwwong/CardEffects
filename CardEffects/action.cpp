#include "action.h"

// -------------------
// CONSTRUCTORS
// -------------------

// Default constructor
Action::Action()
{
}

Action::~Action() {}

// -------------------
// METHODS
// -------------------

// returns  the original string command
QString Action::GetStringCommand() {
    return stringCommand;
}

void Action::SetStringCommand(QString commandStr) {
    this->stringCommand = commandStr;
}

