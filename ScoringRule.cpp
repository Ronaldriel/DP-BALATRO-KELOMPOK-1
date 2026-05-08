#include <iostream>
#include "ScoringRule.h"
#include "HandCheckers.h"

ScoringRule::ScoringRule() {
    // Chain dari TERTINGGI ke TERENDAH
    // FlushFive -> FlushHouse -> FiveOfAKind -> RoyalFlush -> StraightFlush
    // -> FourOfAKind -> FullHouse -> Flush -> Straight
    // -> ThreeOfAKind -> TwoPair -> Pair -> HighCard
    static FlushFiveChecker     flushFive;
    static FlushHouseChecker    flushHouse;
    static FiveOfAKindChecker   fiveOfAKind;
    static RoyalFlushChecker    royalFlush;
    static StraightFlushChecker straightFlush;
    static FourOfAKindChecker   fourOfAKind;
    static FullHouseChecker     fullHouse;
    static FlushChecker         flush;
    static StraightChecker      straight;
    static ThreeOfAKindChecker  threeOfAKind;
    static TwoPairChecker       twoPair;
    static PairChecker          pair;
    static HighCardChecker      highCard;

    flushFive.setNext(&flushHouse);
    flushHouse.setNext(&fiveOfAKind);
    fiveOfAKind.setNext(&royalFlush);
    royalFlush.setNext(&straightFlush);
    straightFlush.setNext(&fourOfAKind);
    fourOfAKind.setNext(&fullHouse);
    fullHouse.setNext(&flush);
    flush.setNext(&straight);
    straight.setNext(&threeOfAKind);
    threeOfAKind.setNext(&twoPair);
    twoPair.setNext(&pair);
    pair.setNext(&highCard);

    checkerChain = &flushFive;
}

int ScoringRule::scoreHand(const ChosenHand& hand) {
    HandRank rank = checkerChain->check(hand);

    int baseScore = convertRankToScore(rank);

    int cardScore = 0;

    for (const auto& card : hand.getCards()) {
        cardScore += static_cast<int>(card.rank);
    }

    return baseScore + cardScore;
}

int ScoringRule::convertRankToScore(HandRank rank) {
    switch (rank) {
        case HandRank::HIGH_CARD:       return 5;
        case HandRank::PAIR:            return 10;
        case HandRank::TWO_PAIR:        return 20;
        case HandRank::THREE_OF_A_KIND: return 30;
        case HandRank::STRAIGHT:        return 30;
        case HandRank::FLUSH:           return 35;
        case HandRank::FULL_HOUSE:      return 40;
        case HandRank::FOUR_OF_A_KIND:  return 60;
        case HandRank::STRAIGHT_FLUSH:  return 100;
        case HandRank::ROYAL_FLUSH:     return 100;
        case HandRank::FIVE_OF_A_KIND:  return 120;
        case HandRank::FLUSH_HOUSE:     return 140;
        case HandRank::FLUSH_FIVE:      return 160;
        default:                        return 0;
    }
}
