#pragma once
#include "IJoker.h"

class HeartJoker : public IJoker
{
public:
    void apply(ScoreResult& score,
               const ChosenHand& hand) override;
};