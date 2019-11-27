#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "queue.h"

int enqueue(struct studentqueue *q, const char *name){

    struct studentqueue *new_node, *p;
    new_node = malloc(sizeof(struct studentqueue));
    //p = malloc(sizeof(struct studentqueue));
    if(new_node==NULL) return 0;
    new_node->name = malloc(strlen(name) + 1);
    strcpy(new_node->name,name);
    new_node->next=NULL;
    p=q;
    while (p->next)
        p = p->next;
    p->next = new_node;
    //free(p);
    return 1;

}

int dequeue(struct studentqueue *q, char *buffer, unsigned int size){

    struct studentqueue *temp;
    //temp = malloc(sizeof(struct studentqueue));

    //If the LL is null:
    /*if(q==NULL) {
        //free(temp);
        return 0;
    }*/
    //If the LL has only one element:
    if(q->next==NULL) {
        
        //if(strlen(q->name)>=size) memmove(buffer,q->name,size-1);
        //else memmove(buffer,q->name,strlen(q->name));
        //free(q);
        //free(temp);
        return 0;
    }

    //If the LL has more than one element:
    
    temp=q->next;
    //q = q->next;
    q->next=temp->next;
   // if(strlen(temp->name)>=size) strncpy(buffer,temp->name,size+1);
   // else memmove(buffer,temp->name,strlen(temp->name));
    strncpy(buffer,temp->name,size+1);

    //q = q->next;
    
    free(temp->name);
    free(temp);
    return 1;
    
}
