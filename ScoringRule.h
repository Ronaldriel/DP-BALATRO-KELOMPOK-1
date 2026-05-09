#pragma once
#include "ChosenHand.h"
#include "PokerHandChecker.h"
#include "ScoreResult.h"

class ScoringRule
{
public:
    ScoringRule();

    ScoreResult scoreHand(const ChosenHand& hand);

    int convertRankToScore(HandRank rank);

private:
    PokerHandChecker* checkerChain;
};