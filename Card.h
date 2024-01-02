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
    void makeHidden();
    void makeVisible();
    bool isFaceUp();
    
    

private:
    Char suit;
    int rank;
    bool faceUp;
};
