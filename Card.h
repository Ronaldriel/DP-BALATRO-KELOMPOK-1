#pragma once
#include <string>

enum Suit
{
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};

enum Rank
{
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

struct Card
{
    Suit suit;
    Rank rank;

    std::string ToString() const
    {
        std::string rStr;

        if (rank <= TEN)
            rStr = std::to_string(static_cast<int>(rank));
        else if (rank == JACK)
            rStr = "J";
        else if (rank == QUEEN)
            rStr = "Q";
        else if (rank == KING)
            rStr = "K";
        else
            rStr = "A";

        std::string sStr;
        if (suit == HEARTS) sStr = "H";
        else if (suit == DIAMONDS) sStr = "D";
        else if (suit == CLUBS) sStr = "C";
        else sStr = "S";

        return rStr + sStr;
    }
};