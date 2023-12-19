#include "BlackJack.h"

namespace GoldenLuck {

    void BlackJack::startGame() {
        dealInitialCards();
        displayHands(false); // Show only one of the dealer's cards initially
        playerTurn();
        dealerTurn();
        determineWinner();
    }

    void BlackJack::dealInitialCards() {
        for (int i = 0; i < 2; ++i) {
            playerHand->Add(deck->dealCard());
            dealerHand->Add(deck->dealCard());
        }
    }

    void BlackJack::playerTurn() {
        // Burada oyuncunun hamleleri yapýlabilir (örneðin: hit or stand)
    }

    void BlackJack::dealerTurn() {
        // Burada daðýtýcýnýn hamleleri yapýlabilir (örneðin: belirli kurallara göre hit or stand)
    }

    void BlackJack::displayHands(bool showAll) {
        // Oyuncu ve daðýtýcý elini göster
        // showAll parametresini kullanarak daðýtýcýnýn kartlarýnýn gizli olup olmadýðýný belirleyin
    }

    void BlackJack::determineWinner() {
        // Ellere dayanarak kazananý belirle
        // playerHand ve dealerHand'i karþýlaþtýrarak kazananý seçin
    }

    // ... Diðer etkinlik iþlevleri ve implementasyonlar
}
