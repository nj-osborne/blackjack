#include "card.h"
#include "deck.h"
#include <string>
#include <algorithm>
#pragma once


class Hand {
    private:
    std::vector<Card> cards;
    
    public:
    void addCard(const Card& card);
    int getTotal() const;
    void printHand(bool hideFirst = false) const;
    void clearHand() { cards.clear(); }
    
    
};