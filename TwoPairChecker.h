#pragma once
#include "PokerHandChecker.H"

class TwoPairChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override;
};
