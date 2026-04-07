#pragma once
#include "PokerHandChecker.H"

class RoyalFlushChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override;
};
