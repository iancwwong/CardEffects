/*
    This class represents an area on the game board that can contain cards
*/
#ifndef CARDAREA_H
#define CARDAREA_H

#include <QString>
#include <QVector>
#include <cardobj.h>
#include <random>

using namespace std;

class CardArea
{

public:

    // ----------------------
    // CONSTRUCTOR / DESTRUCTOR
    // ----------------------
    CardArea();
    CardArea(QString area, QString player, QVector<CardObj> cardList, bool pvisible, bool ovisible);
    ~CardArea();

    // ----------------------
    // METHODS
    // ----------------------

    // Get the number of cards
    int NumCards();

    // Display the cards
    void ShowCards();

    // Remove the card at a specified index
    CardObj RemoveCard(int index);

    // Add a card at a specified index
    void AddCard(CardObj card, int index);

    // Obtain an instance of the card
    CardObj VewCard(int index);

    // Randomise the order of the cards
    void ShuffleCards();


private:

    // ---------------------
    // ATTRIBUTES
    // ---------------------
    QString areaName;
    QString playerName;             // Associated player
    QVector<CardObj> cards;
    bool visibleToPlayer;
    bool visibleToOpponent;

    // ---------------------
    // METHODS
    // ---------------------
    // Generate a random number between 0 and a specified number (inclusive)
    int RandNum(int upperBound);
};

#endif // CARDAREA_H
