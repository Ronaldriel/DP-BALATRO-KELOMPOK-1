#include <iostream>
#include "PairChecker.h"

HandRank PairChecker::check(const Hand& hand) {
    std::cout << "Hand: Pair\n";
    return HandRank::PAIR;
}
