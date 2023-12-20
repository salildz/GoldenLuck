#include "card.h"

Card::Card() {
    suit = ' ';
    rank = 0;
}

Card::Card(char newSuit, int newRank) {
    if (newSuit != 'H' && newSuit != 'D' && newSuit != 'C' && newSuit != 'S') {
        throw std::invalid_argument("Invalid suit!");
    }
    else {
        suit = newSuit;
    }

    if (newRank < 1 || newRank > 13) {
        throw std::invalid_argument("Invalid rank!");
    }
    else {
        rank = newRank;
    }

}

char Card::getSuit() {
    return suit;
}

void Card::setSuit(char newSuit) {
    if (newSuit != 'H' && newSuit != 'D' && newSuit != 'C' && newSuit != 'S') {
        throw std::invalid_argument("Invalid suit!");
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
        throw std::invalid_argument("Invalid rank!");
    }
    else {
        rank = newRank;
    }
}
