#pragma once
#include "PokerHandChecker.H"

class StraightChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override;
};
