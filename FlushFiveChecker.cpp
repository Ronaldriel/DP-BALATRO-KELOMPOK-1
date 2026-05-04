#include <iostream>
#include "FlushFiveChecker.h"

// Flush Five: Five of a Kind (5 rank sama) DAN semua suit sama (Balatro specific)
HandRank FlushFiveChecker::check(const ChosenHand& hand) {
    auto counts = hand.getRankCounts();
    for (auto& [rank, cnt] : counts) {
        if (cnt >= 5 && hand.isSameSuit()) {
            std::cout << "Hand: Flush Five\n";
            return HandRank::FLUSH_FIVE;
        }
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
