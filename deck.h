#pragma once
#include <vector>
#include "card.h"

//Deck class to manage a collection of cards.

class Deck {
    private:
    std::vector<Card> cards;
    int index; 

    public:
    Deck(); 
    void shuffle(); 
    Card dealCard(); 
    bool isEmpty() const;
};