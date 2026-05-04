#pragma once
#include "ChosenHand.h"
#include "PokerHandChecker.H"

class ScoringRule {
public:
    ScoringRule();
    int scoreHand(const ChosenHand& hand);
    int convertRankToScore(HandRank rank);
private:
    PokerHandChecker* checkerChain;
};
