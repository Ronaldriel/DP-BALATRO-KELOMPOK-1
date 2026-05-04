#pragma once
#include <random>
#include "Card.h"

struct Hand {
    std::vector<Card> cards;
    int value ;
    Hand() {
        static std::mt19937 rng(std::random_device{}());
        static std::uniform_int_distribution<int> dist(0, 12);
        value = dist(rng);
    }
};