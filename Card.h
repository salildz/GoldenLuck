#pragma once

using namespace System;

public ref class Card {
public:
    Card();
    Card(Char newSuit, int newRank);
    Char getSuit();
    void setSuit(Char newSuit);
    int getRank();
    void setRank(int newRank);

private:
    Char suit;
    int rank;
};
