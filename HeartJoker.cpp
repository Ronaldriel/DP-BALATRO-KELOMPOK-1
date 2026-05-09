#include "HeartJoker.h"

void HeartJoker::apply(ScoreResult& score,
                       const ChosenHand& hand)
{
    int heartCount = 0;

    for (const auto& card : hand.getCards())
    {
        if (card.suit == HEARTS)
            heartCount++;
    }

    score.multiplier += heartCount;
}