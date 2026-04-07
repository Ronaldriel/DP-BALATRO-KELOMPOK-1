#include <iostream>
#include "StraightFlushChecker.h"

HandRank StraightFlushChecker::check(const Hand& hand) {
    std::cout << "Hand: Straight Flush\n";
    return HandRank::STRAIGHT_FLUSH;
}
