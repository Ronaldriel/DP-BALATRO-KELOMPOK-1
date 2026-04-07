#pragma once
#include "Hand.h"
#include "PokerHandChecker.H"

class ScoringRule {
public:
    ScoringRule();
    int scoreHand(const Hand& hand);
    int convertRankToScore(HandRank rank);
private:
    PokerHandChecker* checkerChain;
};
