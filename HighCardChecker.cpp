#include <iostream>
#include "HighCardChecker.h"

HandRank HighCardChecker::check(const Hand& hand) {
    std::cout << "Hand: High Card\n";
    return HandRank::HIGH_CARD;
}
