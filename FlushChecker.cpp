#include <iostream>
#include "FlushChecker.h"

HandRank FlushChecker::check(const ChosenHand& hand) {
    // TAMBAHKAN VALIDASI INI:
    // Flush hanya valid jika pemain memilih tepat 5 kartu.
    if (hand.getCards().size() != 5) {
        if (nextChecker) return nextChecker->check(hand);
        return HandRank::HIGH_CARD;
    }

    if (hand.isSameSuit() && !hand.isStraight()) {
        auto counts = hand.getRankCounts();
        int maxCount = 0;

        // Structured binding ini yang tadi menyebabkan error jika tidak pakai C++17
        for (auto& [r, c] : counts) {
            if (c > maxCount) maxCount = c;
        }

        // Pastikan bukan FlushFive/FlushHouse
        if (maxCount < 3) {
            std::cout << "Hand: Flush\n";
            return HandRank::FLUSH;
        }
    }

    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}