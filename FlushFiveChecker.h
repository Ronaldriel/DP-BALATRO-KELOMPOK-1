#pragma once
#include "PokerHandChecker.H"

class FlushFiveChecker : public PokerHandChecker {
public:
    HandRank check(const ChosenHand& hand) override;
};
