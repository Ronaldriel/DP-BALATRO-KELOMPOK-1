#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "HandGenerator.h"

Hand HandGenerator::generateHand() {
    std::cout << "Generating cards for player...\n";

    std::vector<Card> deck;

    // bikin 52 kartu
    for (int s = HEARTS; s <= SPADES; s++) {
        for (int r = TWO; r <= ACE; r++) {
            deck.push_back({ (Suit)s, (Rank)r });
        }
    }

    // shuffle deck
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);

    Hand hand;

    // ambil 8 kartu pertama 
    for (int i = 0; i < 8; i++) {
        hand.cards.push_back(deck[i]);
    }

    std::cout << "Generated Cards:\n";

    int i = 1;
        for (const auto& card : hand.cards) {
    std::cout << i++ << ". " << card.ToString() << "\n";
}
    
    return hand;
}