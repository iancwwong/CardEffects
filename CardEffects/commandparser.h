/*
 * This class is responsible for checking the validity of user-entered commands
 * and if a valid command, pass as an "Action" to the "GameEngine" class.
 * Then returns a result string to the UI.
 *
 * If a command is invalid, then it will return an error message to the UI instead.
 *
*/

#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

// DATA RESPRESENTATION
#include <QString>
#include <QStringList>

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
    QStringList * commandList;

    // ---------------------
    // FUNCTIONS
    // ---------------------

    bool CheckCommand(QString command);
    bool CheckParameters(QStringList commandComponents);

};

#endif // COMMANDPARSER_H
