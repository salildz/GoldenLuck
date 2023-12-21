#include "Card.h"

Card::Card() {
    suit = ' ';
    rank = 0;
}

Card::Card(Char newSuit, int newRank) {
    if (newSuit != 'H' && newSuit != 'D' && newSuit != 'C' && newSuit != 'S') {
        throw gcnew System::ArgumentException("Invalid suit!");
    }
    else {
        suit = newSuit;
    }

    if (newRank < 1 || newRank > 13) {
        throw gcnew System::ArgumentException("Invalid rank!");
    }
    else {
        rank = newRank;
    }
}

Char Card::getSuit() {
    return suit;
}

void Card::setSuit(Char newSuit) {
    if (newSuit != 'H' && newSuit != 'D' && newSuit != 'C' && newSuit != 'S') {
        throw gcnew System::ArgumentException("Invalid suit!");
    }
    else {
        suit = newSuit;
    }
}

int Card::getRank() {
    return rank;
}

void Card::setRank(int newRank) {
    if (newRank < 1 || newRank > 13) {
        throw gcnew System::ArgumentException("Invalid rank!");
    }
    else {
        rank = newRank;
    }
}
 