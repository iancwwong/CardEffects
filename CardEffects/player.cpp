/*
 *  This class represents a player
*/

#include "player.h"

Player::Player()
{}

Player::Player(QString newPlayerName, int newId) {
    playerName = newPlayerName;
    id = newId;
}

Player::~Player()
{}

// ---------------------
// METHODS
// ---------------------

QString Player::GetPlayerName() {
    return playerName;
}

int Player::GetPlayerId() {
    return id;
}

void Player::SetPlayerName(QString newPlayerName) {
    playerName = newPlayerName;
}


