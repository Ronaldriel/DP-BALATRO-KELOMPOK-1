#pragma once
#include "PokerHandChecker.H"

class FourOfAKindChecker : public PokerHandChecker {
public:
    HandRank check(const ChosenHand& hand) override;
};
