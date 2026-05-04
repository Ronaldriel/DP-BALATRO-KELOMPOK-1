#pragma once
#include "Hand.h"
#include "ChosenHand.h"

class HandPlayer {
public:
    // Pilih 5 kartu acak dari hand (simulasi pemain memilih)
    ChosenHand playHand(const Hand& hand);
};
