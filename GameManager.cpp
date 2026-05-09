#include <iostream>
#include "GameManager.h"
#include "HeartJoker.h"

void GameManager::runSession()
{
    std::cout << "=== Run Started ===\n";

    Hand hand = handGenerator.generateHand();
    ChosenHand chosen = handPlayer.playHand(hand);

    ScoreResult result = scoringRule.scoreHand(chosen);

    std::vector<IJoker*> jokers;

    jokers.push_back(new HeartJoker());

    for (auto joker : jokers)
    {
        joker->apply(result, chosen);
    }

    int finalScore = result.getFinalScore();

    std::cout << "Base Score : " << result.baseScore << "\n";
    std::cout << "CardValue: " << result.cardValue << "\n";
    std::cout << "Multiplier : " << result.multiplier << "\n";
    std::cout << "Final Score: " << finalScore << "\n";

    bool win = blindRule.checkBlind(finalScore);

    int reward = rewardRule.earnMoney(win, finalScore);

    std::cout << "Money gained: " << reward << "\n";
    std::cout << "=== Run Ended ===\n";

    for (auto joker : jokers)
    {
        delete joker;
    }
}

