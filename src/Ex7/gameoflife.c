#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aaltogame.h"

GameArea *createGameArea(unsigned int x_size, unsigned int y_size){
	GameArea *area = malloc(sizeof(GameArea));
	area->x_size=x_size;
	area->y_size=y_size;
	area->cells = malloc(y_size * sizeof(CellStatus *));
	for (int j = 0; j < y_size; j++) {
		area->cells[j] = malloc(x_size * sizeof(CellStatus));
		for (int i = 0; i < x_size; i++) {
			// fill matrix with DEAD status
			area->cells[j][i] = DEAD;
		}
	}
	return area;
}

int count_alive(int pos_y, int pos_x, GameArea *a){
	int counter=0;

		if(pos_y-1>=0 && pos_x-1>=0) {
			if(a->cells[pos_y-1][pos_x-1]==ALIVE) counter++;
		}
		if(pos_y-1>=0) {
			if(a->cells[pos_y-1][pos_x]==ALIVE) counter++;
		}
		if(pos_y-1>=0 && pos_x+1<a->x_size) {
			if(a->cells[pos_y-1][pos_x+1]==ALIVE) counter++;
		}
		if(pos_x-1>=0) {
			if(a->cells[pos_y][pos_x-1]==ALIVE) counter++;
		}
		if(pos_x+1<a->x_size){
			if(a->cells[pos_y][pos_x+1]==ALIVE) counter++;
		}
		if(pos_y+1<a->y_size && pos_x-1 >=0){
			if(a->cells[pos_y+1][pos_x-1]==ALIVE) counter++;
		}
		if(pos_y+1<a->y_size){
			if(a->cells[pos_y+1][pos_x]==ALIVE) counter++;
		}
		if(pos_y+1<a->y_size && pos_x+1<a->x_size){
			if(a->cells[pos_y+1][pos_x+1]==ALIVE) counter++;
		}
	return counter;
}

void releaseGameArea(GameArea *a){
	for (int j = 0; j < a->y_size; j++) {
		free(a->cells[j]); //First release each column
	}
	free(a->cells); //Then release the whole array
	free(a);
}

void initGameArea(GameArea *a, unsigned int n){
	int rand_x;
	int rand_y;
	int counter = 0;
	while(counter<n){
		rand_x = rand() % a->x_size;
		rand_y = rand() % a->y_size;
		if(a->cells[rand_y][rand_x] != ALIVE){
			a->cells[rand_y][rand_x] = ALIVE;
			counter++;
		}
	}
}


void printGameArea(const GameArea *a){
	for(int y=0;y<a->y_size;y++){
		for(int x=0;x<a->x_size;x++){
			if(a->cells[y][x]==ALIVE) printf("*");
			else printf(".");
		}
	printf("\n");
	}

}

void gameTick(GameArea *a){
	int	lives,i,j;
	GameArea *newboard =createGameArea(a->x_size, a->y_size);
	for (i=0; i<a->y_size; i++) {
		for (j=0; j<a->x_size; j++) {
			newboard->cells[i][j] = a->cells[i][j];
		}
	}

	for ( i=0; i<a->y_size; i++) {
		for ( j=0; j<a->x_size; j++) {
			lives = count_alive(i,j,a);
			if(a->cells[i][j]==ALIVE){
				if (lives < 2) newboard->cells[i][j] = DEAD;
				if (lives == 3 || lives==2) newboard->cells[i][j] = ALIVE;
				if (lives > 3) newboard->cells[i][j] = DEAD; 
			}
			if(a->cells[i][j]==DEAD){
				if(lives==3) newboard->cells[i][j] = ALIVE;
			}
		}
	}

	for (i=0; i<a->y_size; i++) {
		for (j=0; j<a->x_size; j++) {
			a->cells[i][j] = newboard->cells[i][j];
		}
	}

	releaseGameArea(newboard);
}


