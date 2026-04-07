#pragma once
#include "PokerHandChecker.H"

class FlushFiveChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override;
};
