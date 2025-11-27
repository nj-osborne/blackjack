#include "game.h"
#include "hand.h"
#include "deck.h"
#include "card.h"   
#include <iostream>
using std::cout;
using std::cin;

//Starts the game by initializing the deck and shuffling it.
Game::Game() {
    deck.shuffle();
}


//Deals the initial two cards to player and dealer.
void Game::dealInitialCards() 
{
    player.clearHand();
    dealer.clearHand();

    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
}

//Handles the player's turn.

void Game::playerTurn()
{
    char choice;
    do {
        showHands(false);
        cout << "Do you want to hit or stand? (h/s) ";
        cin >> choice;
        if(choice == 'h')
        {
            player.addCard(deck.dealCard());
            if(player.getTotal() > 21)
            {
                showHands(false);
                cout << "You bust! Dealer wins." << std::endl;
                return;
            }
        }
    }while (choice != 's');
}

//Handles the dealer's turn.

void Game::dealerTurn()
{
   // showHands(false);
    while (dealer.getTotal() < 17) 
    {
        cout << "Dealer hits." << std::endl;
        dealer.addCard(deck.dealCard());
        cout << "Dealer's total is now " << dealer.getTotal() << std::endl;
    }

    if (dealer.getTotal() > 21) 
    {
        cout << "Dealer busts! You win!" << std::endl;
    }

}

//Displays the hands of both player and dealer.

void Game::showHands(bool hideDealerCard) const {
    std::cout << "Dealer: ";
    dealer.printHand(false);

    std::cout << "Player: ";
    player.printHand(false);

    std::cout << "\n";
}

//Determines and displays the result of the game.

void Game::showResult() const {
    int p = player.getTotal();
    int d = dealer.getTotal();

    if (p > 21)         std::cout << "Dealer wins.\n";
    else if (d > 21)    std::cout << "You win!\n";
    else if (p > d)     std::cout << "You win!\n";
    else if (p < d)     std::cout << "Dealer wins.\n";
    else                std::cout << "Push (tie).\n";
}

//Asks the player if they want to play again.

bool Game::askPlayAgain() const
{
    char c;
    cout << "Do you want to play again? (y/n) ";
    cin >> c;
    if( c == 'y')
        return true;
    else
        return false;
}

//Main game loop.

void Game::play()
{
    do {
        
        player.clearHand();
        dealer.clearHand();
        deck.shuffle();

        dealInitialCards();
        playerTurn();
        if (player.getTotal() <= 21) {
            dealerTurn();
        }
        showResult();
    } while (askPlayAgain());
}


