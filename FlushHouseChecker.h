#pragma once
#include "PokerHandChecker.H"

class FlushHouseChecker : public PokerHandChecker {
public:
    HandRank check(const ChosenHand& hand) override;
};
