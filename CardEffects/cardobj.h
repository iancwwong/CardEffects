/*
 *  This class represents a card in this card effects game
 *
*/

#ifndef CARDOBJ_H
#define CARDOBJ_H

#include <QString>

// Card State
#define FACE_DOWN 0
#define FACE_UP 1


class CardObj
{

public:
    CardObj();
    CardObj(QString cname, QString strname, QChar s, int cvalue, int plevel, int cstate);
    ~CardObj();

    // -------------------------
    // METHODS
    // -------------------------

    // Getters
    QString GetCodeName();
    QString GetStrName();
    QChar GetSuit();
    int GetCardValue();
    int GetCardPowerLevel();
    int GetCardState();

    // Setters
    void SetCodeName(QString newCodeName);
    void SetStrName(QString newStrName);
    void SetSuit(QChar newSuit);
    void SetCardValue(int newCardValue);
    void SetCardPowerLevel(int newPowerLevel);
    void SetCardState(int newState);

private:

    // -------------------------
    // ATTRIBUTES
    // -------------------------
    QString cardCodeName;       // shortened card name eg HJ
    QString cardStrName;        // full card name eg Hearts: Jack
    QChar cardSuit;             // card id eg H
    int cardValue;              // card id eg 11
    int cardPowerLevel;         // combat power
    int cardState;              // face up / face down

};

#endif // CARDOBJ_H
