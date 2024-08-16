#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int p1[5][5], p2[5][5], key;
char m1[20], m2[20];

// Function to generate unique random numbers between 1 and 25
void generate_random_board(int board[5][5]) {
    int used[26] = {0}; // Array to keep track of used numbers

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int num;
            do {
                num = rand() % 25 + 1; // Generate numbers between 1 and 25
            } while (used[num]);
            used[num] = 1;
            board[i][j] = num;
        }
    }
}

// Function to print the board
void print_board(char *name, int board[5][5]) {
    printf("\n%s's Board:\n", name);
    printf(" -------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf(" |");
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == -1) {
                printf("  X  |"); // Print X for crossed-out numbers
            } else {
                printf(" %2d  |", board[i][j]);
            }
        }
        printf("\n -------------------------------\n");
    }
}

// Function to handle the player's move
void player_move(int board[5][5], int key) {
    if (key < 1 || key > 25) {
        printf("Warning: Number must be between 1 and 25!\n");
        return;
    }
    int found = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == key) {
                board[i][j] = -1; // Mark the number as crossed with X
                found = 1;
            }
        }
    }
    if (!found) {
        printf("Warning: Number not found on the board!\n");
    }
}

// Function to check for Bingo (five in a row/column/diagonal)
int check_bingo(int board[5][5]) {
    int count = 0;

    // Check rows and columns
    for (int i = 0; i < 5; i++) {
        if (board[i][0] == -1 && board[i][1] == -1 && board[i][2] == -1 && board[i][3] == -1 && board[i][4] == -1) {
            count++;
        }
        if (board[0][i] == -1 && board[1][i] == -1 && board[2][i] == -1 && board[3][i] == -1 && board[4][i] == -1) {
            count++;
        }
    }

    // Check diagonals
    if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
        count++;
    }
    if (board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1) {
        count++;
    }

    return count;
}

// Function to check and declare the winner
void check_winner(int c1, int c2) {
    if (c1 == 5 && c2 != 5) {
        printf("\n\n***************************************************\n");
        printf("BINGO!!!! Congratulations %s, You are the Winner! \n", m1);
        printf("***************************************************\n\n");
        exit(0);
    } else if (c2 == 5 && c1 != 5) {
        printf("\n\n*****************************************************\n");
        printf("BINGO!!!! Congratulations %s, You are the Winner!\n", m2);
        printf("*****************************************************\n\n");
        exit(0);
    } else if (c1 == 5 && c2 == 5) {
        printf("\n\n*************************************************\n");
        printf("It's a Tie! Well Played %s and %s!\n", m1, m2);
        printf("*************************************************\n\n");
        exit(0);
    }
}

// Main game loop
int main() {
    srand(time(0)); // Seed the random number generator

    printf("Enter name for player 1: ");
    scanf("%s", m1);
    generate_random_board(p1);

    printf("Enter name for player 2: ");
    scanf("%s", m2);
    generate_random_board(p2);

    while (1) {
        print_board(m1, p1);
        print_board(m2, p2);

        printf("\n%s's turn. Enter key to cross: ", m1);
        scanf("%d", &key);
        player_move(p1, key);
        player_move(p2, key);

        int c1 = check_bingo(p1);
        int c2 = check_bingo(p2);
        check_winner(c1, c2);

        print_board(m1, p1);
        print_board(m2, p2);

        printf("\n%s's turn. Enter key to cross: ", m2);
        scanf("%d", &key);
        player_move(p2, key);
        player_move(p1, key);

        c1 = check_bingo(p1);
        c2 = check_bingo(p2);
        check_winner(c1, c2);
    }

    return 0;
}
