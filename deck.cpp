#include "deck.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <stdexcept>


// Using declarations
using std::vector;
using std::string;


// Checks if the deck is empty.
bool Deck::isEmpty() const {
    return index >= cards.size();
}

// Constructor for the Deck class.
Deck::Deck() : index(0) {
    for (int s = 0; s < 4; ++s) {
        for (int r = 1; r <= 13; ++r) {
            cards.emplace_back(
                static_cast<Card::rank>(r),
                static_cast<Card::suit>(s),
                0);
        }
    }
}

//Shuffles the deck of cards.
void Deck::shuffle()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
    index = 0;
}

//Deals a card from the deck.
Card Deck::dealCard()
{
    if (isEmpty()) {
        throw std::out_of_range("No cards left in the deck");
    }
    return cards[index++];
}