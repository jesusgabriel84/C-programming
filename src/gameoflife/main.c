#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "gameoflife.h"

int main(void)
{
    /* Feel free to modify this function to test different things */
    int cols, rows, rounds, alives;

    // re-seed random number generator
    srand((unsigned)time(NULL));

    printf("Enter The number of columns: \n");
    scanf("%d", &cols);

    printf("Enter The number of rows: \n");
    scanf("%d", &rows);

    printf("Enter The number of rounds: \n");
    scanf("%d", &rounds);

    printf("Enter The number of organisms to initialize the grid: \n");
    scanf("%d", &alives);

    GameArea *a = createGameArea(cols,rows);
    initGameArea(a, alives);

    // loop iterations, cancel with ctrl-c
    for(int i=0; i<rounds; i++) {
        printf("\nGeneration: %d\n", i+1);
        printGameArea(a);
        // slow down iterations
        sleep(1);
        gameTick(a);
    }
    releaseGameArea(a);
    return 0;
}
