#pragma once

ref class Card {
private:
    int cardNum;
    System::Char cardSign;

public:
    Card(); // Constructor
    Card(int num, System::Char sign); // Constructor with parameters
    int getCardNum(); // Getter for cardNum
    void setCardNum(int num); // Setter for cardNum
    System::Char getCardSign(); // Getter for cardSign
    void setCardSign(System::Char sign); // Setter for cardSign
    void displayCard(); // Function to display card details
};

