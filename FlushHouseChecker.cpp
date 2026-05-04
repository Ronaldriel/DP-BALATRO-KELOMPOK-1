#include <iostream>
#include "FlushHouseChecker.h"

// Flush House: Full House (3+2) DAN semua suit sama (Balatro specific)
HandRank FlushHouseChecker::check(const ChosenHand& hand) {
    auto counts = hand.getRankCounts();
    int threes = 0, pairs = 0;
    for (auto& [rank, cnt] : counts) {
        if (cnt >= 3) threes++;
        else if (cnt == 2) pairs++;
    }

    if (threes == 1 && pairs == 1 && hand.isSameSuit()) {
        std::cout << "Hand: Flush House\n";
        return HandRank::FLUSH_HOUSE;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
