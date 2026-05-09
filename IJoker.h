#pragma once
#include "ScoreResult.h"
#include "ChosenHand.h"

class IJoker
{
public:
    virtual void apply(ScoreResult& score,
                       const ChosenHand& hand) = 0;

    virtual ~IJoker() = default;
};