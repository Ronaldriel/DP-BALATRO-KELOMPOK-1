#include <iostream>
#include "FiveOfAKindChecker.h"

// Five of a Kind: 1 rank muncul 5 kali (Balatro: pakai joker/wildcard), suit tidak semua sama
HandRank FiveOfAKindChecker::check(const ChosenHand& hand) {
    auto counts = hand.getRankCounts();
    for (auto& [rank, cnt] : counts) {
        if (cnt >= 5 && !hand.isSameSuit()) {
            std::cout << "Hand: Five of a Kind\n";
            return HandRank::FIVE_OF_A_KIND;
        }
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
