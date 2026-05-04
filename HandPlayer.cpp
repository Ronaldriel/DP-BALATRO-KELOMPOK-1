#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include "HandPlayer.h"

ChosenHand HandPlayer::playHand(const Hand& hand) {
    const auto& cards = hand.cards;

    std::cout << "\nYour current hand:\n";
    for (int i = 0; i < (int)cards.size(); ++i) {
        std::cout << "[" << i << "] ";
        
    }

    ChosenHand chosen;
    std::vector<int> selectedIndices;
    int inputIndex;

    std::cout << "\nSelect 1 to 5 cards to play.\n";
    std::cout << "Enter index (0-7) to select, or enter '-1' to finish selecting.\n";

    while (selectedIndices.size() < 5) {
        std::cout << "Card " << (selectedIndices.size() + 1) << " (or -1 to play): ";

        if (!(std::cin >> inputIndex)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Jika user input -1, berhenti dari loop dan mainkan kartu yang sudah dipilih
        if (inputIndex == -1) {
            if (selectedIndices.empty()) {
                std::cout << "You must select at least one card!\n";
                continue;
            }
            break;
        }

        // Validasi input
        if (inputIndex < 0 || inputIndex >= (int)cards.size()) {
            std::cout << "Index out of range!\n";
        }
        else if (std::find(selectedIndices.begin(), selectedIndices.end(), inputIndex) != selectedIndices.end()) {
            std::cout << "Already selected!\n";
        }
        else {
            selectedIndices.push_back(inputIndex);
            chosen.selectCard(cards[inputIndex]); 
        }
    }

    std::cout << "\nPlaying hand...\n";
    chosen.print(); 
        return chosen;
}