#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include "ChosenHand.h"

namespace HandUtils {

    // Returns {rank -> count} map
    inline std::map<int,int> rankCounts(const std::vector<Card>& cards) {
        std::map<int,int> counts;
        for (const auto& c : cards) counts[static_cast<int>(c.rank)]++;
        return counts;
    }

    // Returns sorted list of counts (descending), e.g. {4,1} for four-of-a-kind
    inline std::vector<int> countValues(const std::map<int,int>& rc) {
        std::vector<int> v;
        for (const auto& p : rc) v.push_back(p.second);
        std::sort(v.rbegin(), v.rend());
        return v;
    }

    // True if all cards share the same suit
    inline bool isFlush(const std::vector<Card>& cards) {
        if (cards.empty()) return false;
        Suit s = cards[0].suit;
        for (const auto& c : cards)
            if (c.suit != s) return false;
        return true;
    }

    // True if cards form 5 consecutive ranks (handles A-low: A,2,3,4,5)
    inline bool isStraight(const std::vector<Card>& cards) {
        if (cards.size() != 5) return false;
        std::vector<int> ranks;
        for (const auto& c : cards) ranks.push_back(static_cast<int>(c.rank));
        std::sort(ranks.begin(), ranks.end());

        // Normal straight
        bool normal = true;
        for (int i = 1; i < 5; i++)
            if (ranks[i] != ranks[i-1] + 1) { normal = false; break; }
        if (normal) return true;

        // A-low straight: 2,3,4,5,A  (ranks = {2,3,4,5,14})
        return ranks[0] == 2 && ranks[1] == 3 && ranks[2] == 4 &&
               ranks[3] == 5 && ranks[4] == static_cast<int>(ACE);
    }

    // True if hand is a royal flush (10,J,Q,K,A same suit)
    inline bool isRoyalFlush(const std::vector<Card>& cards) {
        if (!isFlush(cards) || cards.size() != 5) return false;
        std::vector<int> ranks;
        for (const auto& c : cards) ranks.push_back(static_cast<int>(c.rank));
        std::sort(ranks.begin(), ranks.end());
        return ranks[0] == static_cast<int>(TEN)  &&
               ranks[1] == static_cast<int>(JACK)  &&
               ranks[2] == static_cast<int>(QUEEN) &&
               ranks[3] == static_cast<int>(KING)  &&
               ranks[4] == static_cast<int>(ACE);
    }

} // namespace HandUtils
