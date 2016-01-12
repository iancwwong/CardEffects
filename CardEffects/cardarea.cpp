#include "cardarea.h"

CardArea::CardArea()
{}

CardArea::CardArea(QString area, QString player, QVector<CardObj> cardList, bool pvisible, bool ovisible) {
    areaName = area;
    playerName = player;
    cards = cardList;
    visibleToPlayer = pvisible;
    visibleToOpponent = ovisible;
}

CardArea::~CardArea()
{
    delete cards;
}

// ----------------------
// METHODS
// ----------------------

// Get the number of cards
int CardArea::NumCards() {
    return cards.size();
}

// Display the cards
void CardArea::ShowCards() {

}

// Remove the card at a specified index
// Assume index is in range
CardObj CardArea::RemoveCard(int index) {
    return cards.remove(index);
}

// Add a card at a specified index
// Assume index is in range
void CardArea::AddCard(CardObj card, int index) {
    cards.insert(index, card);
}

// Obtain an instance of the card
CardObj CardArea::VewCard(int index) {
    return cards[index];
}

// Randomise the order of the cards
void CardArea::ShuffleCards() {
    // Take a random card, and append to end of card list
    int i = cards.size();
    while (i != 0) {
        CardObj tempCard = cards.remove(RandNum(i-1));
        cards.append(tempCard);
        i--;
    }

}

// Generate a random number between 0 and a specified number (inclusive)
int CardArea::RandNum(int upperBound) {

    // Create the engine and distributor
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, upperBound);

    return distribution(generator);
}

