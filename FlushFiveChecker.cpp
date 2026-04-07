#include <iostream>
#include "FlushFiveChecker.h"

HandRank FlushFiveChecker::check(const Hand& hand) {
    std::cout << "Hand: Flush Five\n";
    return HandRank::FLUSH_FIVE;
}
