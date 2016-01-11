/*
 *  This class represents a player
*/

#include "player.h"

Player::Player()
{}

Player::Player(QString newPlayerName) {
    playerName = newPlayerName;
}

Player::~Player()
{}

// ---------------------
// METHODS
// ---------------------

QString Player::GetPlayerName() {
    return playerName;
}

void Player::SetPlayerName(QString newPlayerName) {
    playerName = newPlayerName;
}


