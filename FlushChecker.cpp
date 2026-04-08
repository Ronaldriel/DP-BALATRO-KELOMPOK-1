#include <iostream>
#include "FlushChecker.h"

HandRank FlushChecker::check(const Hand& hand) {
    std::cout << "Hand: Flush\n";
    return HandRank::FLUSH;
}
