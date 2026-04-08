#include <iostream>
#include "ThreeOfAKindChecker.h"

HandRank ThreeOfAKindChecker::check(const Hand& hand) {
    std::cout << "Hand: Three of a Kind\n";
    return HandRank::THREE_OF_A_KIND;
}
