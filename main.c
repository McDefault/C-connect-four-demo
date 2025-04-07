#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 7
#define FALSE 0

// Functie om een getal te promten
int prompt_cords() {
    int num;

    while(1) {
        printf("Enter a number between 0 and 10: ");
        if(scanf("%d", &num) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // clear input buffer
        } else if(num < 0 || num > 10) {
            printf("The number you entered is not between 0 and 10.\n");
        } else {
            printf("You entered %d which is between 0 and 10.\n", num);
            return num;
        }
    }
}


char option_A = '^';
char option_B = '*';

char *ptr_option1 = &option_A;
char *ptr_option2 = &option_B;
typedef enum { DISC_A, DISC_B } DiscType;

typedef struct {
    char *grid[ROWS][COLS];
} Board;


Board make_board() {

    Board board;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board.grid[i][j] = NULL; // Geen schijf, dus NULL pointer
        }
    }
    return board;

}


int place_disk(Board *board, char *disc, int col) {
    if (col < 0 || col >= COLS) {
        printf("Ongeldige kolom.\n");
        return -1;
    }
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board->grid[i][col] == NULL) {
            board->grid[i][col] = disc;
            return i;
        }
    }
    printf("Kolom is vol.\n");
    return -1;
}

int weghalen_chip(Board *board, int row, int col) {

    for (int i = row; i >= 1; i--) {

        if (board->grid[i - 1][col] != NULL) {

            printf("%d zit boven (%d, %d)\n", board->grid[i - 1][col], i, col);

            board->grid[i][col] = board->grid[i - 1][col];

        }

        else {
            board->grid[i][col] = NULL;
        }
    }
    return 1;

}


int main() {
//
//    int x;
//    printf("What column to place?? ");
//    x = prompt_cords();

    char option_A = '^';
    char option_B = '*';

    char *ptr_option1 = &option_A;
    char *ptr_option2 = &option_B;


// maak raster
    Board board = make_board();

    char disc = *ptr_option2;
    int col = 5;
    place_disk(&board, disc, 0);
    place_disk(&board, disc, 0);
    place_disk(&board, disc, 1);
    place_disk(&board, disc, 2);
    place_disk(&board, disc, 3);
    place_disk(&board, disc, 3);
    place_disk(&board, disc, 3);
    place_disk(&board, disc, 3);
    int row = place_disk(&board, disc, 5);

    if (row != -1) {
        int i = row;
        int row_count = 0;
        int last_column_index = -1;

        // check 4 op een rij horizontal
        for (int j = 0; j < COLS; j++) {

            char disc_actual= board.grid[i][j];

            if (disc_actual == disc) {
                printf("%d Gevonden op positie (%d, %d)\n", disc_actual, i, j);
                row_count++;
            } else {
                row_count = 0;
            }

            if (row_count > 3) {
                printf("4 op een rij Gevonden op positie (%d, %d)\n", disc_actual, i, j);

                last_column_index = j;
            }

        }
        // weghalen discs
        if (last_column_index != -1) {
            for (int j = last_column_index; j >= 0; j--) {
                // printf("%d weghalen op positie (%d, %d)\n", disc, i, j);
                // board.grid[i][j] = NULL;
                weghalen_chip(&board, i, j);

            }
        }

    }

// print raster
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {

            if (board.grid[i][j] == NULL) {
                printf(". ");
            } else {
                printf("%c ", (board.grid[i][j]));
            }

        }
        printf("\n");
    }

    return FALSE;
}


