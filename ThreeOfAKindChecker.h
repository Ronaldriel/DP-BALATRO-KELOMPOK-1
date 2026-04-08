#pragma once
#include "PokerHandChecker.H"

class ThreeOfAKindChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override;
};
