#pragma once
#include "PokerHandChecker.H"

class FlushChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override;
};
