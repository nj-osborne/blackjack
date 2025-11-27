#include "deck.h"
#include "hand.h"
#pragma once

//Game class to manage the overall game logic.
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

