#pragma once
#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

class Deck {
public:
    Deck();
    std::vector<Card> cards;
    void shuffleDeck();
    void resetDeck();
};

#endif // DECK_H
