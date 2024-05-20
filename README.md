# Tic Tac Toe - Console Game

Classic Tic Tac Toe game, designed for two players to enjoy directly from the command line. 
Written entirely in C, this project is perfect for learning basic game logic, practicing programming concepts, or just having fun with a timeless game.


```
      A     B     C
   -------------------
1  |  X  |  O  |  X  |
   -------------------
2  |  O  |  X  |  O  |
   -------------------
3  |  X  |  X  |  O  |
   -------------------
```
   

## Features
  * Two Player Mode: Play against a friend in a turn-based match.
  * Simple UI: Console-based interface that is easy to use and understand.
  * Input Validation: Ensures that players choose valid moves.
  * Winning Detection: Automatically detects and announces the winner or a tie.

## Getting Started
To get started with the Tic Tac Toe Console Game, follow these simple steps:
**1. Clone the Repository**
```bash
    git clone https://github.com/masi23/TicTacToe.git
    cd TicTacToe
```
**2. Compile the Program**
```bash
gcc -o TicTacToe.c
```

## How to Play
- The game board is a 3x3 grid labeled with rows (1-3) and columns (A-C).
- Players take turns to place their marker (`X` or `O`) on the board.
- To make a move, enter the desired cell (e.g., `A1`, `B2`).
- The game checks for a winner after 5th move.
- The game ends when one player wins or all cells are filled resulting in a tie.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.
