# Bingo Game
This Bingo game is a two-player console application written in C. Players take turns marking numbers on their Bingo boards, which are generated with unique random numbers between 1 and 25. The game checks for Bingo conditions (five in a row, column, or diagonal) and declares a winner or a tie.

# Features
Random Board Generation: Each player receives a unique Bingo board with random numbers between 1 and 25.

**Player Turns:** Players alternate turns to mark numbers on their boards.
**Input Validation:** Checks for valid input numbers and provides warnings if an invalid number is entered or if the number is not found on the board.
**Bingo Detection:** Automatically detects when a player has achieved Bingo and declares the winner or a tie.
**Decorative Output:** Includes decorative and congratulatory messages to enhance user experience.

# Requirements
**C compiler** (e.g., gcc or clang or geany)

# Instructions
**Enter Player Names:**
The program will prompt you to enter names for Player 1 and Player 2.

**Bingo Board Generation:**
Each player's Bingo board will be automatically generated with unique random numbers between 1 and 25.

**Player Turns:**
Players take turns entering a number they want to mark. The board will update to show an X for marked numbers.

**Game Progress:**
The game will check for Bingo conditions after each turn and declare a winner or a tie if the condition is met.

**Warnings:**
If an invalid number is entered or if the number is not found on the board, a warning message will be displayed.

**Winning Message:**
When a player achieves Bingo, a congratulatory message will be displayed, and the game will end.

# Troubleshooting
**Program Not Compiling:** Ensure that you have a C compiler installed and that the source file is named correctly.
**Invalid Input:** Make sure that the numbers entered are between 1 and 25.

# License
This project is licensed under the MIT License - see the LICENSE file for details.
