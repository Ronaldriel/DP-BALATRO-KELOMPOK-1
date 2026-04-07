#include <iostream>
#include "ScoringRule.h"
#include "HandCheckers.h"

ScoringRule::ScoringRule() {
    // Build chain (lowest to highest priority)
    static HighCardChecker     highCard;
    static PairChecker         pair;
    static TwoPairChecker      twoPair;
    static ThreeOfAKindChecker threeOfAKind;
    static StraightChecker     straight;
    static FlushChecker        flush;
    static FullHouseChecker    fullHouse;
    static FourOfAKindChecker  fourOfAKind;
    static StraightFlushChecker straightFlush;
    static RoyalFlushChecker   royalFlush;
    static FiveOfAKindChecker  fiveOfAKind;
    static FlushHouseChecker   flushHouse;
    static FlushFiveChecker    flushFive;

    highCard.setNext(&pair);
    pair.setNext(&twoPair);
    twoPair.setNext(&threeOfAKind);
    threeOfAKind.setNext(&straight);
    straight.setNext(&flush);
    flush.setNext(&fullHouse);
    fullHouse.setNext(&fourOfAKind);
    fourOfAKind.setNext(&straightFlush);
    straightFlush.setNext(&royalFlush);
    royalFlush.setNext(&fiveOfAKind);
    fiveOfAKind.setNext(&flushHouse);
    flushHouse.setNext(&flushFive);

    checkerChain = &highCard;
}

int ScoringRule::scoreHand(const Hand& hand) {
    // Traverse chain hand.value kali agar checker yang sesuai yang dipanggil
    PokerHandChecker* current = checkerChain;
    for (int i = 0; i < hand.value && current->getNext() != nullptr; i++) {
        current = current->getNext();
    }
    HandRank rank = current->check(hand);
    return convertRankToScore(rank);
}

int ScoringRule::convertRankToScore(HandRank rank) {
    switch (rank) {
        case HandRank::HIGH_CARD:      return 5;
        case HandRank::PAIR:           return 10;
        case HandRank::TWO_PAIR:       return 20;
        case HandRank::THREE_OF_A_KIND:return 30;
        case HandRank::STRAIGHT:       return 30;
        case HandRank::FLUSH:          return 35;
        case HandRank::FULL_HOUSE:     return 40;
        case HandRank::FOUR_OF_A_KIND: return 60;
        case HandRank::STRAIGHT_FLUSH: return 100;
        case HandRank::ROYAL_FLUSH:    return 100;
        case HandRank::FIVE_OF_A_KIND: return 120;
        case HandRank::FLUSH_HOUSE:    return 140;
        case HandRank::FLUSH_FIVE:     return 160;
        default:                       return 0;
    }
}
