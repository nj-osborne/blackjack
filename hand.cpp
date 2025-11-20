#include "card.h"
#include "hand.h"
#include <string>
#include <iostream>


using std::vector;
using std::string;

void Hand::addCard(const Card& card)
{
    cards.push_back(card);
}

int Hand::getTotal() const
{
    int total = 0;
    int aceCount = 0;
    string aVal;

    for (const auto& card : cards) {
        total += card.getVal();
        if (card.getRank() == Card::rank::ACE){
            aceCount++;
        }
        
    }

    while (aceCount > 0 && total + 10 <= 21) {
        total += 10;
        aceCount--;
    }

    return total;
}

void Hand::printHand(bool hideFirst) const {
    for (size_t i = 0; i < cards.size(); ++i) {
        if (hideFirst && i == 0) {
            std::cout << "?? ";
        } else {
            std::cout << cards[i].toString() << " ";
        }
    }
    std::cout << "\n";
}

