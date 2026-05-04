#pragma once
#include "PokerHandChecker.H"

class FlushChecker : public PokerHandChecker {
public:
    HandRank check(const ChosenHand& hand) override;
};
