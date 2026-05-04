#pragma once
#include "Card.h"
#include <vector>
#include <map>
#include <algorithm>

class ChosenHand {
public:
    // Tambah kartu ke chosen hand (maks 5)
    bool selectCard(const Card& card);

    // Hapus semua kartu
    void clear();

    // Getter
    const std::vector<Card>& getCards() const;
    int size() const;

    // ── Helper untuk checker ───────────────────────────────────────────────

    // Map rank -> jumlah kemunculan
    std::map<Rank, int> getRankCounts() const;

    // Map suit -> jumlah kemunculan
    std::map<Suit, int> getSuitCounts() const;

    // Semua kartu suit yang sama?
    bool isSameSuit() const;

    // 5 kartu berurutan? (A bisa rendah: A-2-3-4-5 atau tinggi: 10-J-Q-K-A)
    bool isStraight() const;

    // Royal Flush: 10-J-Q-K-A semua suit sama?
    bool isRoyalFlush() const;

    // Cetak kartu yang dipilih
    void print() const;

private:
    std::vector<Card> cards;
    static const int MAX_CARDS = 5;
};
