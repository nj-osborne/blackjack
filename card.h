#include <string>
#pragma once

//Using declaration
using std::string;

//Card class to represent a playing card.
class Card {
    public:
    enum class rank {ACE = 1, TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
    enum class suit {HEARTS, DIAMONDS, CLUBS, SPADES};
    int val;
    rank rnk;
    suit st;


    
    Card(rank r,suit s, int v);
    rank getRank() const;
    suit getSuit() const;
    int getVal() const;
    string toString() const;
};