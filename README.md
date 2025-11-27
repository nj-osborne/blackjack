## blackjack

Simple blackjack game that handles all the fundamental actions in a terminal based game.

## Features

- Object-oriented design using C++
- Custom `Card`, `Deck`, `Hand`, and `Game` classes
- Enum-based modeling for card ranks and suits
- 52-card deck with randomized shuffling
- Player hit/stand gameplay loop
- Automatic Ace value adjustment (11 → 1 when needed)
- Terminal-based user interface
- Exception-safe card dealing
- Git version control workflow

## Build Instructions

### Windows (MinGW / g++)

g++ main.cpp game.cpp deck.cpp hand.cpp card.cpp -o blackjack.exe

Run:
blackjack.exe

### Linux / macOS
g++ main.cpp game.cpp deck.cpp hand.cpp card.cpp -o blackjack

Run:
./blackjack