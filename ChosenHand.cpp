#include <iostream>
#include <set>
#include "ChosenHand.h"

bool ChosenHand::selectCard(const Card& card) {
    if ((int)cards.size() >= MAX_CARDS) {
        std::cout << "[ChosenHand] Max " << MAX_CARDS << " kartu sudah dipilih.\n";
        return false;
    }
    cards.push_back(card);
    return true;
}

void ChosenHand::clear() { cards.clear(); }

const std::vector<Card>& ChosenHand::getCards() const { return cards; }

int ChosenHand::size() const { return static_cast<int>(cards.size()); }

std::map<Rank, int> ChosenHand::getRankCounts() const {
    std::map<Rank, int> counts;
    for (const auto& c : cards) counts[c.rank]++;
    return counts;
}

std::map<Suit, int> ChosenHand::getSuitCounts() const {
    std::map<Suit, int> counts;
    for (const auto& c : cards) counts[c.suit]++;
    return counts;
}

bool ChosenHand::isSameSuit() const {
    if (cards.empty()) return false;
    Suit s = cards[0].suit;
    for (const auto& c : cards)
        if (c.suit != s) return false;
    return true;
}

bool ChosenHand::isStraight() const {
    if ((int)cards.size() < 5) return false;

    std::vector<int> ranks;
    for (const auto& c : cards)
        ranks.push_back(static_cast<int>(c.rank));

    std::sort(ranks.begin(), ranks.end());
    ranks.erase(std::unique(ranks.begin(), ranks.end()), ranks.end());
    if ((int)ranks.size() != 5) return false;

    // Straight biasa
    if (ranks[4] - ranks[0] == 4) return true;

    // A-low: A-2-3-4-5
    if (ranks[4] == static_cast<int>(ACE) &&
        ranks[0] == static_cast<int>(TWO) &&
        ranks[1] == static_cast<int>(THREE) &&
        ranks[2] == static_cast<int>(FOUR) &&
        ranks[3] == static_cast<int>(FIVE))
        return true;

    return false;
}

bool ChosenHand::isRoyalFlush() const {
    if (!isSameSuit() || (int)cards.size() < 5) return false;
    std::set<Rank> royalRanks = { TEN, JACK, QUEEN, KING, ACE };
    for (const auto& c : cards)
        if (royalRanks.find(c.rank) == royalRanks.end()) return false;
    return true;
}

void ChosenHand::print() const {
    std::cout << "Chosen cards: ";
    for (const auto& c : cards)
        std::cout << c.ToString() << " ";
    std::cout << "\n";
}
