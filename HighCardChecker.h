#pragma once
#include "PokerHandChecker.H"

class HighCardChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override;
};
