#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int main(void)
{
	//Initializing the queue
	struct studentqueue q = { NULL, NULL };

	int go_on = 1;
	char buffer[100];
	while(go_on) {
		printf("Enter name of the student (\"-\" will end reading): ");
		scanf("%99s", buffer);
		if (strcmp(buffer, "-")) {
			go_on = enqueue(&q, buffer);
        } else {
			go_on = 0;
        }
	}

	//Testing the dequeuing of the data stored in the linked list
	while(dequeue(&q, buffer, 100)) {
	    printf("Fetching %s from queue\n", buffer);
	}

	return 0;
}