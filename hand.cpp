#include "card.h"
#include "hand.h"
#include <string>
#include <iostream>

// Using declarations
using std::vector;
using std::string;

//Adds a card to the hand.

void Hand::addCard(const Card& card)
{
    cards.push_back(card);
}

//Calculates the total value of the hand.
int Hand::getTotal() const
{
    int total = 0;
    int aceCount = 0;

    for (const auto& card : cards) 
    {
        total += card.getVal();
        if (card.getRank() == Card::rank::ACE)
        {
            aceCount++;
        }
    }

    while (aceCount > 0 && total + 10 <= 21) 
    {
        total += 10;
        aceCount--;
    }

    return total;
}


//Prints the hand, optionally hiding the first card.
void Hand::printHand(bool hideFirst) const 
{
    for (size_t i = 0; i < cards.size(); ++i) 
    {
        if (hideFirst && i == 0) 
        {
            std::cout << "?? ";
        } 
        else 
        {
            std::cout << cards[i].toString() << " ";
        }
    }
    std::cout << "\n";
}

