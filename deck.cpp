#include "deck.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <stdexcept>


    
using std::vector;
using std::string;



bool Deck::isEmpty() const {
    return index >= cards.size();
}

Deck::Deck() : index(0) {
    for (int s = 0; s < 4; ++s) {
        for (int r = 1; r <= 13; ++r) {
            cards.emplace_back(
                static_cast<Card::rank>(r)
                ,static_cast<Card::suit>(s),
                0);
        }
    }
}

void Deck::shuffle()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
    index = 0;
}

Card Deck::dealCard()
{
    if (isEmpty()) {
        throw std::out_of_range("No cards left in the deck");
    }
    return cards[index++];
}