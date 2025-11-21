#include "card.h"
#include <string>
#include <iostream>


Card::Card(rank r,suit s, int v) : rnk(r), st(s), val(v) {}

Card::rank Card::getRank() const {
        return rnk;
    }

Card::suit Card::getSuit() const {
        return st;
    }

int Card::getVal() const {
    int r = static_cast<int>(rnk);
    if (r >= 2 <= 10 )
    return r;

    if (r >=11 && r <=13)
    return r = 10;
    
    return 11;
}

string Card::toString() const {
    string rankStr;
    switch (rnk) {
        case rank::ACE: rankStr = "Ace"; break;
        case rank::TWO: rankStr = "2"; break;
        case rank::THREE: rankStr = "3"; break;
        case rank::FOUR: rankStr = "4"; break;
        case rank::FIVE: rankStr = "5"; break;
        case rank::SIX: rankStr = "6"; break;
        case rank::SEVEN: rankStr = "7"; break;
        case rank::EIGHT: rankStr = "8"; break;
        case rank::NINE: rankStr = "9"; break;
        case rank::TEN: rankStr = "10"; break;
        case rank::JACK: rankStr = "Jack"; break;
        case rank::QUEEN: rankStr = "Queen"; break;
        case rank::KING: rankStr = "King"; break;
    }

    string suitStr;
    switch (st) {
        case suit::HEARTS: suitStr = "Hearts"; break;
        case suit::DIAMONDS: suitStr = "Diamonds"; break;
        case suit::CLUBS: suitStr = "Clubs"; break;
        case suit::SPADES: suitStr = "Spades"; break;
    }

    return rankStr + " of " + suitStr;
}



