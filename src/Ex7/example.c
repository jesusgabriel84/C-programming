#include <stdio.h>
#include <stdlib.h>

void printArray(int **arr, int xs, int ys) {
	int i,j;
	// Print the matrix in rectangular format
	for (j = 0; j < ys; j++) {
		for (i = 0; i < xs; i++) {
			printf("%2d ", arr[j][i]);
		}
		printf("\n");
	}
}

int main(void) {
	int **arr_p;
	int xdim = 4;
	int ydim = 5;

    // first allocate array that points to arrays of rows
    // (notice the data type in sizeof operation)
	arr_p = malloc(ydim * sizeof(int *));
	if (!arr_p)
		return -1; // memory allocation failed

	for (int j = 0; j < ydim; j++) {
		arr_p[j] = malloc(xdim * sizeof(int));
		if (!arr_p[j]) {
            // memory allocation failed, release memory
			// will have to go through previously allocated rows
			for (int i = 0; i < j; i++) {
				free(arr_p[i]);
			}
			free(arr_p);
			return -1;
		}
		for (int i = 0; i < xdim; i++) {
			// fill matrix with values, multiplication table
			arr_p[j][i] = (i+1) * (j+1);
		}
	}

	printArray(arr_p, xdim, ydim);

	// release the memory
	for (int j = 0; j < ydim; j++) {
		free(arr_p[j]); //First release each column
	}
	free(arr_p); //Then release the whole array
}