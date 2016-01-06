/*
 * This class is responsible for decrypting the meaning of user-entered commands
 * and if a valid command, pass as a "GameAction" to the "GameEngine" class.
 * Finally, returns a result string to the UI.
 *
 * If a command is invalid, then it will return an error message back to the user.
 *
*/

#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <QString>

#include <gameengine.h>
#include <action.h>

class CommandParser
{

public:

    CommandParser();
    ~CommandParser();

    // ---------------------
    // METHODS
    // ---------------------

    // Attach a GameEngine
    void SetGameEngine(GameEngine * newGameEngine);

    // Decrypt the meaning of a user-entered command
    QString ParseCommand(QString command);

private:
    GameEngine * gameEngine;

};

#endif // COMMANDPARSER_H
