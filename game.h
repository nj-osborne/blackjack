#include "deck.h"
#include "hand.h"
#pragma once

class Game {
public:
    Deck deck;
    Hand player;
    Hand dealer;

    void dealInitialCards();
    void playerTurn();
    void dealerTurn();
    void showHands(bool hideDealerCard) const;
    void showResult() const;
    bool askPlayAgain() const;


    Game();
    void play();
};

