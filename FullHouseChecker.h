#pragma once
#include "PokerHandChecker.H"

class FullHouseChecker : public PokerHandChecker {
public:
    HandRank check(const ChosenHand& hand) override;
};
