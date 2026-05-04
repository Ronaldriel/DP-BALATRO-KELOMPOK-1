#include <iostream>
#include "StraightChecker.h"

// Straight: 5 rank berurutan, suit tidak sama semua
HandRank StraightChecker::check(const ChosenHand& hand) {
    if (hand.isStraight() && !hand.isSameSuit()) {
        std::cout << "Hand: Straight\n";
        return HandRank::STRAIGHT;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
