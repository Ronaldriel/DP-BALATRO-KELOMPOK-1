#include <iostream>
#include "StraightFlushChecker.h"

// Straight Flush: straight + semua suit sama, bukan Royal Flush
HandRank StraightFlushChecker::check(const ChosenHand& hand) {
    if (hand.isStraight() && hand.isSameSuit() && !hand.isRoyalFlush()) {
        std::cout << "Hand: Straight Flush\n";
        return HandRank::STRAIGHT_FLUSH;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
