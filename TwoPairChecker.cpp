#include <iostream>
#include "TwoPairChecker.h"

HandRank TwoPairChecker::check(const Hand& hand) {
    std::cout << "Hand: Two Pair\n";
    return HandRank::TWO_PAIR;
}
