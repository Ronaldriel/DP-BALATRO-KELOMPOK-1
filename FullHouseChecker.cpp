#include <iostream>
#include "FullHouseChecker.h"

HandRank FullHouseChecker::check(const Hand& hand) {
    std::cout << "Hand: Full House\n";
    return HandRank::FULL_HOUSE;
}
