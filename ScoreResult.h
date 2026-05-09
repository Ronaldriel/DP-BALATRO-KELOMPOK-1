#pragma once

struct ScoreResult
{
    int baseScore = 0;
    int cardValue = 0;
    int multiplier = 1;

    int getFinalScore() const
    {
        return (baseScore + cardValue) * multiplier;
    }
};