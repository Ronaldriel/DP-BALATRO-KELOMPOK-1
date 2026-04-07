#include <iostream>
#include "FiveOfAKindChecker.h"

HandRank FiveOfAKindChecker::check(const Hand& hand) {
    std::cout << "Hand: Five of a Kind\n";
    return HandRank::FIVE_OF_A_KIND;
}
