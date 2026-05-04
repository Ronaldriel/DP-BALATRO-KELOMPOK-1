#include <iostream>
#include "FlushChecker.h"

// Flush: semua suit sama, bukan straight
HandRank FlushChecker::check(const ChosenHand& hand) {
    if (hand.isSameSuit() && !hand.isStraight()) {
        auto counts = hand.getRankCounts();
        int maxCount = 0;
        for (auto& [r, c] : counts) if (c > maxCount) maxCount = c;
        // Pastikan bukan FlushFive/FlushHouse (ditangani checker lebih tinggi)
        if (maxCount < 3) {
            std::cout << "Hand: Flush\n";
            return HandRank::FLUSH;
        }
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
