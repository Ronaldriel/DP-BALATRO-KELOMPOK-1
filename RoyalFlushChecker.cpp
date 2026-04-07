#include <iostream>
#include "RoyalFlushChecker.h"

HandRank RoyalFlushChecker::check(const Hand& hand) {
    std::cout << "Hand: Royal Flush\n";
    return HandRank::ROYAL_FLUSH;
}
