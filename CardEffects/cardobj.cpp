#include "cardobj.h"

// ---------------------------
// CONSTRUCTORS + DESTRUCTORS
// ---------------------------
CardObj::CardObj()
{}

CardObj::CardObj(QString cname, QString strname, QChar s, int cvalue, int plevel, int cstate) {
    cardCodeName = cname;
    cardStrName = strname;
    cardSuit = s;
    cardValue = cvalue;
    cardPowerLevel = plevel;
    cardState = cstate;
}

CardObj::~CardObj()
{}

// --------------------------
// METHODS
// --------------------------

// Getters
QString CardObj::GetCodeName() {
    return cardCodeName;
}

QString CardObj::GetStrName() {
    return cardStrName;
}

QChar CardObj::GetSuit() {
    return cardSuit;
}

int CardObj::GetCardValue() {
    return cardValue;
}

int CardObj::GetCardPowerLevel() {
    return cardPowerLevel;
}

int CardObj::GetCardState() {
    return cardState;
}

// Setters
void CardObj::SetCodeName(QString newCodeName) {
    cardCodeName = newCodeName;
}

void CardObj::SetStrName(QString newStrName) {
    cardStrName = newStrName;
}

void CardObj::SetSuit(QChar newSuit) {
    cardSuit = newSuit;
}

void CardObj::SetCardValue(int newCardValue) {
    cardValue = newCardValue;
}

void CardObj::SetCardPowerLevel(int newPowerLevel) {
    cardPowerLevel = newPowerLevel;
}

void CardObj::SetCardState(int newState) {
    cardState = newState;
}

