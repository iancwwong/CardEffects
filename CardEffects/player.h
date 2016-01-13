#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player
{
public:
    Player();
    Player(QString newPlayerName, int newId);
    ~Player();

    // ---------------------
    // METHODS
    // ---------------------

    QString GetPlayerName();
    int GetPlayerId();
    void SetPlayerName(QString newPlayerName);

private:
    QString playerName;
    int id;
};

#endif // PLAYER_H
