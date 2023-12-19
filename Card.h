#pragma once

ref class Card {
private:
    int cardNum;
    char cardSign;

public:
    Card(); // Constructor
    Card(int num, char sign); // Constructor with parameters
    int getCardNum(); // Getter for cardNum
    void setCardNum(int num); // Setter for cardNum
    char getCardSign(); // Getter for cardSign
    void setCardSign(char sign); // Setter for cardSign
    Card^ getCard(); // Function to display card details
};

