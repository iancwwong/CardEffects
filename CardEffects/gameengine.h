/*
 * This class is responsible for controlling and maintaining the state of the game through user commands
 * while the game has not ended.
 *
 * A new GameEngine object is constructed whenever there a new game is started.
*/

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QString>
#include <action.h>


class GameEngine
{

public:

    // Constructor, destructor
    GameEngine();
    ~GameEngine();

    // ---------------------------
    // METHODS
    // ---------------------------
    QString ExecuteAction(Action action);

private:
    // ---------------------------
    // Attributes
    // ---------------------------

    // GameState * gameState;
    // GameLogger * gameLogger;

    // ---------------------------
    // METHODS
    // ---------------------------

};

#endif // GAMEENGINE_H
