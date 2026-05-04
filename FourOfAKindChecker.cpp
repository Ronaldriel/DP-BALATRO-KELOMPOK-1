#include <iostream>
#include "FourOfAKindChecker.h"

// Four of a Kind: 1 rank muncul >= 4 kali
HandRank FourOfAKindChecker::check(const ChosenHand& hand) {
    auto counts = hand.getRankCounts();
    for (auto& [rank, cnt] : counts) {
        if (cnt >= 4) {
            std::cout << "Hand: Four of a Kind\n";
            return HandRank::FOUR_OF_A_KIND;
        }
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
