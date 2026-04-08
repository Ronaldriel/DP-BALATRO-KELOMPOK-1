#include <iostream>
#include "StraightChecker.h"

HandRank StraightChecker::check(const Hand& hand) {
    std::cout << "Hand: Straight\n";
    return HandRank::STRAIGHT;
}
