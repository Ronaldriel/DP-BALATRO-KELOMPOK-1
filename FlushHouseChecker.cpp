#include <iostream>
#include "FlushHouseChecker.h"

HandRank FlushHouseChecker::check(const Hand& hand) {
    std::cout << "Hand: Flush House\n";
    return HandRank::FLUSH_HOUSE;
}
