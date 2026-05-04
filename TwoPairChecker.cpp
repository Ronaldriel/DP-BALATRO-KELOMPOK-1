#include <iostream>
#include "TwoPairChecker.h"

// Two Pair: tepat 2 rank berbeda masing-masing muncul >= 2 kali
HandRank TwoPairChecker::check(const ChosenHand& hand) {
    auto counts = hand.getRankCounts();
    int pairs = 0;
    for (auto& [rank, cnt] : counts)
        if (cnt >= 2) pairs++;

    if (pairs >= 2) {
        std::cout << "Hand: Two Pair\n";
        return HandRank::TWO_PAIR;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
