#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "queue.h"

int enqueue(struct studentqueue *q, const char *name){

    struct studentqueue *new_node, *p;
    new_node = malloc(sizeof(struct studentqueue));

    if(new_node==NULL) return 0;

    new_node->name = malloc(strlen(name) + 1);
    strcpy(new_node->name,name);
    new_node->next=NULL;
    p=q;

    //Moving to the last element of the list that is not NULL
    while (p->next)
        p = p->next;
    p->next = new_node;

    return 1;

}

int dequeue(struct studentqueue *q, char *buffer, unsigned int size){

    struct studentqueue *temp;
    
    //Checking if the Linked List contains only one element:
    if(q->next==NULL) {
        return 0;
    }

    //In case there is more than one element:
    temp=q->next;
    q->next=temp->next;
    strncpy(buffer,temp->name,size+1);
    
    //Releasing the memory allocated for the temporary variable
    free(temp->name);
    free(temp);
    return 1;
    
}
