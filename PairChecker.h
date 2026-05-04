#pragma once
#include "PokerHandChecker.H"

class PairChecker : public PokerHandChecker {
public:
    HandRank check(const ChosenHand& hand) override;
};
