#include <iostream>
#include "ThreeOfAKindChecker.h"

// Three of a Kind: tepat 1 rank muncul >= 3 kali, tanpa pair lain
HandRank ThreeOfAKindChecker::check(const ChosenHand& hand) {
    auto counts = hand.getRankCounts();
    int threes = 0, pairs = 0;
    for (auto& [rank, cnt] : counts) {
        if (cnt >= 3) threes++;
        else if (cnt == 2) pairs++;
    }

    if (threes == 1 && pairs == 0) {
        std::cout << "Hand: Three of a Kind\n";
        return HandRank::THREE_OF_A_KIND;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
