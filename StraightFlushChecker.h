#pragma once
#include "PokerHandChecker.H"

class StraightFlushChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override;
};
