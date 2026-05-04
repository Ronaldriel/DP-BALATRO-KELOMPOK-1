#include <iostream>
#include "PairChecker.h"

// Pair: tepat 1 rank muncul >= 2 kali
HandRank PairChecker::check(const ChosenHand& hand) {
    auto counts = hand.getRankCounts();
    int pairs = 0;
    for (auto& [rank, cnt] : counts)
        if (cnt >= 2) pairs++;

    if (pairs == 1) {
        std::cout << "Hand: Pair\n";
        return HandRank::PAIR;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
