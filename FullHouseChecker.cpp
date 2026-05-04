#include <iostream>
#include "FullHouseChecker.h"

// Full House: 1 three-of-a-kind + 1 pair, suit tidak semua sama
HandRank FullHouseChecker::check(const ChosenHand& hand) {
    auto counts = hand.getRankCounts();
    int threes = 0, pairs = 0;
    for (auto& [rank, cnt] : counts) {
        if (cnt >= 3) threes++;
        else if (cnt == 2) pairs++;
    }

    if (threes == 1 && pairs == 1 && !hand.isSameSuit()) {
        std::cout << "Hand: Full House\n";
        return HandRank::FULL_HOUSE;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
