#include <iostream>
#include "FourOfAKindChecker.h"

HandRank FourOfAKindChecker::check(const Hand& hand) {
    std::cout << "Hand: Four of a Kind\n";
    return HandRank::FOUR_OF_A_KIND;
}
