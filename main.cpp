#include <iostream>
#include "game.h"
using namespace std;

int main() {
    char choice;
    cout << "Welcome to Blackjack!" << endl;
    cout << "This is a simple console-based Blackjack game." << endl;
    cout << "Type p to play or q to quit: ";
    cin >> choice;
    if(choice == 'p')
    {
        Game game;
        game.play();
        
    }    
    cout << "Thanks for playing!" << endl;
    return 0;
}