#include <stdio.h>
#include <stdlib.h>

#define FALSE 0


// fase 0 opties
// optie 0 leeg en niet gegokt
int leeg = 0;
// optie 1 geplaatst niet gegokt
int geplaatst = 1;


//optie 2 fout gegokt
int fout = 2;
// optie 3 goed gegokt
int goed = 3;

int *ptr_option1 = &leeg;
int *ptr_option2 = &geplaatst;
int *ptr_option3 = &fout;
int *ptr_option4 = &goed;

int (*raster)[10];

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
// Functie om een getal te promten
int prompt_direction() {
    int num;

    while(1) {
        printf("Enter a '0' for Horizontal or '1' for vertical: ");
        if(scanf("%d", &num) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // clear input buffer
        } else if(num < 0 || num > 1) {
            printf("The number you entered is not 0 or 1.\n");
        } else {
            printf("You entered %d which is 0 or 1.\n", num);
            return num;
        }
    }
}

int place_ship(int y, int x) {
    x--;
    y--;
    raster[x][y] = *ptr_option2;
}

int main() {
//    // 0 = plaatsen
//    // 1 = raden
//
//    int fase = 0;
//
//    int x, y, d;
//    printf("What is the X cord? ");
//    x = prompt_cords();
//    printf("What is the Y cord? ");
//    y = prompt_cords();
//    printf("What direction of the ship? ");
//    d = prompt_direction();





    raster = malloc(sizeof(int[10][10]));

    // Initialize the raster with leeg
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            raster[i][j] = *ptr_option1;
        }
    }

    // Change a raster item at a specific x, y coordinate
    int x = 2; // x-coordinate
    int y = 3; // y-coordinate
//    raster[y][x] = *ptr_option2; // Change the raster item at (x, y) to the second option

    place_ship(x, y);
    place_ship(1, 1);
    place_ship(2, 2);
    place_ship(3, 3);

    // Print the raster
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            printf("%d ", raster[i][j]);
        }
        printf("\n");
    }

    free(raster);


//    raster[1][1] = geplaatst;

    return FALSE;
}


