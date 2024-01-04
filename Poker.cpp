#include "Poker.h"
using namespace System;
using namespace System::Collections::Generic;

namespace GoldenLuck {

    void Poker::initializeGame() {
        userHand = gcnew Hand();
        dealerHand = gcnew Hand();
        pokerTableHand = gcnew Hand();
        deck = gcnew Deck();
        deck->shuffleDeck();
        bet = 200;
        dealCard(userHand);
        dealCard(userHand);
        dealHiddenCard(dealerHand);
        dealHiddenCard(dealerHand);
        dealCard(pokerTableHand);
        dealCard(pokerTableHand);
        dealCard(pokerTableHand);
        dealCard(pokerTableHand);
        dealCard(pokerTableHand);
    }
    void Poker::loadDealerCardImages()
{
    pnlGame->Controls->Clear();
    array<PictureBox^>^ cardPictureBoxes1 = gcnew array<PictureBox^>(dealerHand->getHand()->Count);
    for (int i = 0; i < dealerHand->getHand()->Count; i++)
    {
        cardPictureBoxes1[i] = gcnew PictureBox();
        cardPictureBoxes1[i]->SizeMode = PictureBoxSizeMode::Zoom; // Resmi PictureBox boyutuna sýðacak þekilde ayarlar
        cardPictureBoxes1[i]->Location = Point(i * 110, 10); // PictureBox'larýn konumu
        cardPictureBoxes1[i]->Size = System::Drawing::Size(110, 154); // PictureBox'larýn boyutu
        if (dealerHand->getHand()[i]->isFaceUp()) {
            
            cardPictureBoxes1[i]->Image = Image::FromFile("cards\\" + dealerHand->getHand()[i]->getRank() + "-" + dealerHand->getHand()[i]->getSuit() + ".png"); // Resmi PictureBox'a atar
        }
        else {
            cardPictureBoxes1[i]->Image = Image::FromFile("cards\\BACK.png");
        }
        pnlGame->Controls->Add(cardPictureBoxes1[i]); // 
    }
    
}

    void Poker::loadUserCardImages()
    {
        array<PictureBox^>^ cardPictureBoxes2 = gcnew array<PictureBox^>(userHand->getHand()->Count);
        for (int i = 0; i < userHand->getHand()->Count; i++)
        {
            cardPictureBoxes2[i] = gcnew PictureBox();
            cardPictureBoxes2[i]->SizeMode = PictureBoxSizeMode::Zoom; 
            cardPictureBoxes2[i]->Location = Point(i * 110, 366); 
            cardPictureBoxes2[i]->Size = System::Drawing::Size(110, 154); 
            cardPictureBoxes2[i]->Image = Image::FromFile("cards\\" + userHand->getHand()[i]->getRank() + "-" + userHand->getHand()[i]->getSuit() + ".png"); // Resmi PictureBox'a atar
            pnlGame->Controls->Add(cardPictureBoxes2[i]); 

        }



    }
    void Poker::loadTableCardImages()
    {

        array<PictureBox^>^ cardPictureBoxes2 = gcnew array<PictureBox^>(pokerTableHand->getHand()->Count);

       
        for (int i = 0; i < pokerTableHand->getHand()->Count; i++)
        {
            cardPictureBoxes2[i] = gcnew PictureBox();
            cardPictureBoxes2[i]->SizeMode = PictureBoxSizeMode::Zoom; 
            cardPictureBoxes2[i]->Location = Point(i * 110, 185); 
            cardPictureBoxes2[i]->Size = System::Drawing::Size(110, 154); 
            cardPictureBoxes2[i]->Image = Image::FromFile("cards\\" + pokerTableHand->getHand()[i]->getRank() + "-" + pokerTableHand->getHand()[i]->getSuit() + ".png"); // Resmi PictureBox'a atar
            pnlGame->Controls->Add(cardPictureBoxes2[i]); 

        }



    }

    void Poker::resetGame() { // reset the game
        userHand = nullptr;
        dealerHand = nullptr;
        pokerTableHand = nullptr;


    }
    void Poker::dealHiddenCard(Hand^ hand) { // deal hidden card
        Card^ temp1 = deck->cards[deck->cards->Count - 1];
        temp1->makeHidden();
        hand->addCardToHand(temp1);
        deck->cards->RemoveAt(deck->cards->Count - 1);

    }

    void Poker::dealCard(Hand^ hand) { //deal open card
        Card^ temp3 = deck->cards[deck->cards->Count - 1];
        hand->addCardToHand(temp3);
        deck->cards->RemoveAt(deck->cards->Count - 1);

    }
    void Poker::endGame() { // end game and show the result

        pnlGame->Controls->Add(lblResult);
    }
    void Poker::faceUpDealerHand() {
        dealerHand->getHand()[0]->makeVisible();
        dealerHand->getHand()[1]->makeVisible();
        loadDealerCardImages();
        loadUserCardImages();
        loadTableCardImages();
        
    }

    Hand^ Poker::sortForRank(Hand^ hand) // sort hand for rank
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (hand->getHand()[j]->getRank() > hand->getHand()[j + 1]->getRank())
                {
                    Card^ temp = hand->getHand()[j];
                    hand->getHand()[j] = hand->getHand()[j + 1];
                    hand->getHand()[j + 1] = temp;
                }
            }
        }
        return hand;
    }

    bool Poker::checkOnePair(Hand^ hand) { // get hand and return true or false for one pair
        int counter = 0;
        hand = sortForRank(hand);
        for (int j = 0; j < (hand->getHand()->Count) - 1; j++) {
            if (hand->getHand()[j]->getRank() == hand->getHand()[j + 1]->getRank()) {
                counter++;

            }
        } if (counter == 1) return true;
        else return false;

    }
    bool Poker::checkTwoPair(Hand^ hand) { // get hand and return true or false for two pair
        hand = sortForRank(hand);
        if (hand->getHand()[0]->getRank() == hand->getHand()[1]->getRank()) {
            if (hand->getHand()[2]->getRank() == hand->getHand()[3]->getRank() && hand->getHand()[4]->getRank() != hand->getHand()[3]->getRank()) {
                if (hand->getHand()[1]->getRank() != hand->getHand()[2]->getRank())
                    return true;
            }
        }if (hand->getHand()[1]->getRank() == hand->getHand()[2]->getRank()) {
            if (hand->getHand()[3]->getRank() == hand->getHand()[4]->getRank() && hand->getHand()[2]->getRank() != hand->getHand()[3]->getRank()) {
                if (hand->getHand()[1]->getRank() != hand->getHand()[0]->getRank()) {
                    return true;
                }
            }
        }if (hand->getHand()[0]->getRank() == hand->getHand()[1]->getRank()) {
            if (hand->getHand()[3]->getRank() == hand->getHand()[4]->getRank()) {
                if (hand->getHand()[1]->getRank() != hand->getHand()[2]->getRank()) {
                    if (hand->getHand()[2]->getRank() != hand->getHand()[3]->getRank()) {
                        return true;
                    }
                }
            }
        }
        else return false;

    }

    bool Poker::checkThreeOfKind(Hand^ hand) { // get hand and return true or false for three of kind
        bool check = false;
        hand = sortForRank(hand);
        if (hand->getHand()[0]->getRank() == hand->getHand()[1]->getRank()) {

            if (hand->getHand()[1]->getRank() == hand->getHand()[2]->getRank()) {

                if (hand->getHand()[2]->getRank() != hand->getHand()[3]->getRank()) {

                    check = true;
                }
            }
        }
        if ((hand->getHand()[1]->getRank() == hand->getHand()[2]->getRank()) && (hand->getHand()[0]->getRank() != hand->getHand()[1]->getRank())) {

            if (hand->getHand()[2]->getRank() == hand->getHand()[3]->getRank()) {

                if (hand->getHand()[3]->getRank() != hand->getHand()[4]->getRank()) {

                    check = true;
                }
            }
        }
        if ((hand->getHand()[2]->getRank() == hand->getHand()[3]->getRank()) && (hand->getHand()[1]->getRank() != hand->getHand()[2]->getRank())) {

            if (hand->getHand()[3]->getRank() == hand->getHand()[4]->getRank()) {

                if (hand->getHand()[0]->getRank() != hand->getHand()[1]->getRank()) {
                    check = true;
                }
            }
        }
        return check;
    }
    bool Poker::checkStraight(Hand^ hand) { // get hand and return true or false for straight
        hand = sortForRank(hand);
        bool check = false;
        for (int i = 0; i < 4; i++)
        {
            if (hand->getHand()[i]->getRank() == hand->getHand()[i + 1]->getRank() - 1) {
                check = true;
            }
            else {
                return false;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            //yanlış
        }



        return check;
    }
    bool Poker::checkFlush(Hand^ hand) { // get hand and return true or false for flush
        hand = sortForRank(hand);
        bool check = false;
        for (int i = 0; i < 4; i++)
        {
            if (hand->getHand()[i]->getRank() != hand->getHand()[i + 1]->getRank() - 1) {
                check = true;
            }
            else {
                check = false;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (hand->getHand()[i]->getSuit() == hand->getHand()[i + 1]->getSuit()) {
                check = true;
            }
            else {
                return false;
            }
        }
        return check;
    }
    bool Poker::checkFullHouse(Hand^ hand) { // get hand and return true or false for full house
        hand = sortForRank(hand);
        bool check = false;

        if (hand->getHand()[0]->getRank() == hand->getHand()[1]->getRank() && hand->getHand()[1]->getRank() == hand->getHand()[2]->getRank()) {
            if (hand->getHand()[3]->getRank() == hand->getHand()[4]->getRank() && hand->getHand()[3]->getRank() != hand->getHand()[2]->getRank()) {
                return true;
            }
            else check = false;
        }if (hand->getHand()[0]->getRank() == hand->getHand()[1]->getRank() && hand->getHand()[1]->getRank() != hand->getHand()[2]->getRank()) {
            if (hand->getHand()[2]->getRank() == hand->getHand()[3]->getRank() && hand->getHand()[3]->getRank() == hand->getHand()[4]->getRank()) {
                return true;
            }
            else check = false;
        }
        return check;
    }
    bool Poker::checkFourOfKind(Hand^ hand) { // get hand and return true or false for four of kind
        hand = sortForRank(hand);
        bool check = false;

        if ((hand->getHand()[0]->getRank() == hand->getHand()[1]->getRank()) && hand->getHand()[1]->getRank() == hand->getHand()[2]->getRank() && hand->getHand()[2]->getRank() == hand->getHand()[3]->getRank()) {
            return true;
        }
        else if ((hand->getHand()[1]->getRank() == hand->getHand()[2]->getRank()) && hand->getHand()[2]->getRank() == hand->getHand()[3]->getRank() && hand->getHand()[3]->getRank() == hand->getHand()[4]->getRank()) {
            return true;
        }
        else return false;
    }
    bool Poker::checkStraightFlush(Hand^ hand) { // get hand and return true or false for straight flush
        bool check = false;
        hand = sortForRank(hand);
        for (int i = 0; i <= 3; ++i) {
            if ((hand->getHand()[i]->getRank() == hand->getHand()[i + 1]->getRank() - 1) && (hand->getHand()[i]->getSuit() == hand->getHand()[i + 1]->getSuit())) {
                if (hand->getHand()[0]->getRank() != 1) {
                    check = true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        } return check;
    }
    bool Poker::checkRoyalFlush(Hand^ hand) { // get hand and return true or false for royal flush
        bool check = false;
        hand = sortForRank(hand);
        for (int i = 0; i <= 3; i++) {
            if (hand->getHand()[0]->getRank() == 1) {
                if ((hand->getHand()[i]->getRank() == hand->getHand()[i + 1]->getRank() - 1) && (hand->getHand()[i]->getSuit() != hand->getHand()[i + 1]->getSuit())) {
                    check = true;
                }
                else {
                    check = false;
                    return false;
                }
            }
            else {
                check = false;
                break;
            }
        }
        return check;
    }
    bool Poker::checkHighCard(Hand^ hand) { // get hand and return true or false for high card
        hand = sortForRank(hand);
        if (!checkFlush(hand) && !checkFourOfKind(hand) && !checkFullHouse(hand) && !checkOnePair(hand) && !checkRoyalFlush(hand)
            && !checkStraight(hand) && !checkStraightFlush(hand) && !checkThreeOfKind(hand) && !checkTwoPair(hand)) {
            return true;
        }
        else return false;
    }

    int Poker::checkForFirstCard(Hand^ hand) { // change pokerTableHand for first card from dealer or user hand and checks the hand
        int maxFirst = 0;
        Card^ firstCard;
        firstCard = hand->getHand()[0];
        int max = 0;
        for (int i = 0; i < 5; ++i) {
            Hand^ temp = gcnew Hand();
            for (int j = 0; j < 5; ++j) {
                if (i == j) {
                    temp->addCardToHand(firstCard); // add first card from dealer or user hand
                }
                else {
                    temp->addCardToHand(pokerTableHand->getHand()[j]); // add other cards from pokerTableHand
                }
            }
            if (checkRoyalFlush(temp)) {
                max = 9;
                maxFirst = (max > maxFirst) ? max : maxFirst;
            }
            if (checkStraightFlush(temp)) {
                max = 8;
                maxFirst = (max > maxFirst) ? max : maxFirst;
            }

            if (checkFourOfKind(temp)) {
                max = 7;
                maxFirst = (max > maxFirst) ? max : maxFirst;
            }

            if (checkFullHouse(temp)) {
                max = 6;
                maxFirst = (max > maxFirst) ? max : maxFirst;
            }

            if (checkFlush(temp)) {
                max = 5;
                maxFirst = (max > maxFirst) ? max : maxFirst;
            }

            if (checkStraight(temp)) {
                max = 4;
                maxFirst = (max > maxFirst) ? max : maxFirst;
            }

            if (checkThreeOfKind(temp)) {
                max = 3;
                maxFirst = (max > maxFirst) ? max : maxFirst;
            }

            if (checkTwoPair(temp)) {
                max = 2;
                maxFirst = (max > maxFirst) ? max : maxFirst;
            }

            if (checkOnePair(temp)) {
                max = 1;
                maxFirst = (max > maxFirst) ? max : maxFirst;
            }

            if (checkHighCard(temp)) {
                max = 0;
                maxFirst = (max > maxFirst) ? max : maxFirst;
            }
        } return maxFirst;
    }
    int Poker::checkForSecondCard(Hand^ hand) { // change pokerTableHand for second card from dealer or user hand and checks the hand
        int maxSecond = 0;
        Card^ secondCard;
        int max = 0;
        secondCard = hand->getHand()[1];
        for (int i = 0; i < 5; ++i) {
            Hand^ temp = gcnew Hand();
            for (int j = 0; j < 5; ++j) {

                if (i == j) {
                    temp->addCardToHand(secondCard);  // add second card from dealer or user hand
                }
                else {
                    temp->addCardToHand(pokerTableHand->getHand()[j]); // add other cards
                }
            }
            if (checkRoyalFlush(temp)) {
                max = 9;
                maxSecond = (max > maxSecond) ? max : maxSecond;
                return 9;
            }

            if (checkStraightFlush(temp)) {
                max = 8;
                maxSecond = (max > maxSecond) ? max : maxSecond;
            }

            if (checkFourOfKind(temp)) {
                max = 7;
                maxSecond = (max > maxSecond) ? max : maxSecond;
            }

            if (checkFullHouse(temp)) {
                max = 6;
                maxSecond = (max > maxSecond) ? max : maxSecond;
            }

            if (checkFlush(temp)) {
                max = 5;
                maxSecond = (max > maxSecond) ? max : maxSecond;
            }

            if (checkStraight(temp)) {
                max = 4;
                maxSecond = (max > maxSecond) ? max : maxSecond;
            }

            if (checkThreeOfKind(temp)) {
                max = 3;
                maxSecond = (max > maxSecond) ? max : maxSecond;
            }

            if (checkTwoPair(temp)) {
                max = 2;
                maxSecond = (max > maxSecond) ? max : maxSecond;
            }

            if (checkOnePair(temp)) {
                max = 1;
                maxSecond = (max > maxSecond) ? max : maxSecond;
            }

            if (checkHighCard(temp)) {
                max = 0;
                maxSecond = (max > maxSecond) ? max : maxSecond;
            }
        } return maxSecond;
    }
    int Poker::checkForBothCard(Hand^ hand) { // gets both card from dealer or user hand and check for both card
        int max = 0;
        int maxBoth = 0;
        Card^ secondCard;
        Card^ firstCard;
        Hand^ temp;
        firstCard = hand->getHand()[0];
        secondCard = hand->getHand()[1];
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                for (int k = j + 1; k < 5; k++) {
                    temp = gcnew Hand();
                    temp->addCardToHand(firstCard);
                    temp->addCardToHand(secondCard);    
                    temp->addCardToHand(pokerTableHand->getHand()[i]);
                    temp->addCardToHand(pokerTableHand->getHand()[j]);
                    temp->addCardToHand(pokerTableHand->getHand()[k]);

                    if (checkRoyalFlush(temp)) {
                        max = 9;
                        maxBoth = (max > maxBoth) ? max : maxBoth;
                        return 9;
                    }

                    if (checkStraightFlush(temp)) {
                        max = 8;
                        maxBoth = (max > maxBoth) ? max : maxBoth;
                    }

                    if (checkFourOfKind(temp)) {
                        max = 7;
                        maxBoth = (max > maxBoth) ? max : maxBoth;
                    }

                    if (checkFullHouse(temp)) {
                        max = 6;
                        maxBoth = (max > maxBoth) ? max : maxBoth;
                    }

                    if (checkFlush(temp)) {
                        max = 5;
                        maxBoth = (max > maxBoth) ? max : maxBoth;
                    }

                    if (checkStraight(temp)) {
                        max = 4;
                        maxBoth = (max > maxBoth) ? max : maxBoth;
                    }

                    if (checkThreeOfKind(temp)) {
                        max = 3;
                        maxBoth = (max > maxBoth) ? max : maxBoth;
                    }

                    if (checkTwoPair(temp)) {
                        max = 2;
                        maxBoth = (max > maxBoth) ? max : maxBoth;
                    }

                    if (checkOnePair(temp)) {
                        max = 1;
                        maxBoth = (max > maxBoth) ? max : maxBoth;
                    }

                    if (checkHighCard(temp)) {
                        max = 0;
                        maxBoth = (max > maxBoth) ? max : maxBoth;
                    }
                }
            }
        }
        return maxBoth;
    } int Poker::checkForNone(Hand^ hand) {  // only check for pokerTableHand without change
        int max = 0;
        int maxNone = 0;
        if (checkRoyalFlush(hand)) {
            max = 9;
            maxNone = (max > maxNone) ? max : maxNone;
        }
        if (checkStraightFlush(hand)) {
            max = 8;
            maxNone = (max > maxNone) ? max : maxNone;
        }
        if (checkFourOfKind(hand)) {
            max = 7;
            maxNone = (max > maxNone) ? max : maxNone;
        }
        if (checkFullHouse(hand)) {
            max = 6;
            maxNone = (max > maxNone) ? max : maxNone;
        }
        if (checkFlush(hand)) {
            max = 5;
            maxNone = (max > maxNone) ? max : maxNone;
        }
        if (checkStraight(hand)) {
            max = 4;
            maxNone = (max > maxNone) ? max : maxNone;
        }
        if (checkThreeOfKind(hand)) {
            max = 3;
            maxNone = (max > maxNone) ? max : maxNone;
        }
        if (checkTwoPair(hand)) {
            max = 2;
            maxNone = (max > maxNone) ? max : maxNone;
        }
        if (checkOnePair(hand)) {
            max = 1;
            maxNone = (max > maxNone) ? max : maxNone;
        }
        if (checkHighCard(hand)) {
            max = 0;
            maxNone = (max > maxNone) ? max : maxNone;
        }
        return maxNone;
    }

    System::Void Poker::btnBet_Click(System::Object^ sender, System::EventArgs^ e) { // after bet it start to check hand and compare them from the vector
        faceUpDealerHand();
        int userMax = 0;
        int dealerMax = 0;
        std::vector<int> compare;
        compare.push_back(checkForFirstCard(userHand));
        compare.push_back(checkForSecondCard(userHand));
        compare.push_back(checkForBothCard(userHand));
        userMax = compare.at(0);
        for (int i = 1; i < 3; i++)
        {
            if (compare.at(i) > userMax) {
                userMax = compare.at(i);
            }
        }
        compare.clear();
        compare.push_back(checkForFirstCard(dealerHand));
        compare.push_back(checkForSecondCard(dealerHand));
        compare.push_back(checkForBothCard(dealerHand));
        dealerMax = compare.at(0);
        for (int i = 1; i < 3; i++)
        {
            if (compare.at(i) > userMax) {
                dealerMax = compare.at(i);
            }
        }compare.clear();
        compare.push_back(checkForNone(pokerTableHand));

        if (compare.at(0) > userMax) {
            userMax = compare.at(0);
        }
        compare.push_back(checkForNone(pokerTableHand));

        if (compare.at(1) > dealerMax) {
            dealerMax = compare.at(1);
        }
        if (userMax > dealerMax) {
            lblResult->Text = "You Win!" + userMax + "  " + dealerMax;
        }
        else if (userMax < dealerMax) {
            lblResult->Text = "You Lose!" + userMax + "  " + dealerMax;
        }
        else if (userMax == dealerMax) {
            lblResult->Text = "Tie!" + userMax + "  " + dealerMax;
        }

        pnlGame->Controls->Add(lblResult);


    }

    System::Void Poker::btnStart_Click(System::Object^ sender, System::EventArgs^ e) { // initialize the game
        resetGame();
        pnlGame->Controls->Clear();
        initializeGame();
        loadDealerCardImages();
        loadUserCardImages();
        loadTableCardImages();
    }
}





