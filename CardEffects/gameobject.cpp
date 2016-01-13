#include "gameobject.h"

// ----------------------------
// CONTSRUCTORS + DESTRUCTORS
// ----------------------------
GameObject::GameObject()
{
    // Card Areas
    deckArea = new CardArea();
    handArea = new CardArea();
    discardArea = new CardArea();
    battleArea = new CardArea();
    shieldArea = new CardArea();

    // Players
    player1 = new Player();
    player2 = new Player();

    // Game Engine
    gameEngine = new GameEngine();

    // Game state
    //gameState = new GameState();
}

GameObject::~GameObject()
{
    delete deckArea;
    delete handArea;
    delete discardArea;
    delete battleArea;
    delete shieldArea;

    delete player1;
    delete player2;

    delete gameEngine;
    // delete gameState;
}

// -------------------
// METHODS
// -------------------

// Execute an action
QString GameObject::ExecuteAction(Action gameAction) {
    return gameEngine->ExecuteAction(gameAction);
}

