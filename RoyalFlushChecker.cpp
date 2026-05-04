#include <iostream>
#include "RoyalFlushChecker.h"

// Royal Flush: 10-J-Q-K-A, semua suit sama
HandRank RoyalFlushChecker::check(const ChosenHand& hand) {
    if (hand.isRoyalFlush()) {
        std::cout << "Hand: Royal Flush\n";
        return HandRank::ROYAL_FLUSH;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
