#include <iostream>
#include "HighCardChecker.h"

// High Card: selalu true — fallback terakhir chain
HandRank HighCardChecker::check(const ChosenHand& hand) {
    std::cout << "Hand: High Card\n";
    return HandRank::HIGH_CARD;
}
