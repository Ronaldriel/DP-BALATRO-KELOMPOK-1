#pragma once
#include "PokerHandChecker.H"

class FiveOfAKindChecker : public PokerHandChecker {
public:
    HandRank check(const ChosenHand& hand) override;
};
