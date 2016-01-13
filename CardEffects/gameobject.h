/*
 * This class represents a game
 *
*/

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <cardarea.h>
#include <player.h>
#include <gameengine.h>
// #include <gamestate.h>

class GameObject
{

public:
    GameObject();
    ~GameObject();

private:

    // -------------------
    // ATTRIBUTES
    // -------------------

    // Card Areas
    CardArea * deckArea;
    CardArea * handArea;
    CardArea * discardArea;
    CardArea * battleArea;
    CardArea * shieldArea;

    // Players
    Player * player1;
    Player * player2;

    // Game Engine
    GameEngine * gameEngine;

    // Game state
    //GameState * gameState;


};

#endif // GAMEOBJECT_H
