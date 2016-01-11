#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player
{
public:
    Player();
    Player(QString newPlayerName);
    ~Player();

    // ---------------------
    // METHODS
    // ---------------------

    QString GetPlayerName();
    void SetPlayerName(QString newPlayerName);

private:
    QString playerName;
};

#endif // PLAYER_H
