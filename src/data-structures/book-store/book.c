#include <stdio.h>
#include <string.h>  // for memcpy
#include <stdlib.h>  // for malloc
#include "book.h"

int init_book(struct book *p_book, const char *p_id, const char *p_title, const char * p_author, struct date p_release){
	if(p_book==NULL) return 0;
	if(strlen(p_id)>9) return 0;
	if(p_book->id==NULL) {free(p_book);return 0;}
	strcpy(p_book->id,p_id);

	p_book->title = malloc(strlen(p_title) + 1);
	if(p_book->title==NULL) {free(p_book);return 0;}
	strcpy(p_book->title, p_title);

	p_book->author = malloc(strlen(p_author) + 1);
	if(p_book->author==NULL) {free(p_book);return 0;}
	strcpy(p_book->author, p_author);

    p_book->release_date.day=p_release.day;
    p_book->release_date.month=p_release.month;
    p_book->release_date.year=p_release.year;

	if(strlen(p_id)<10) {strcpy(p_book->id,p_id); return 1;}
	else return 0;
}

struct book *add_to_collection(struct book *collection, unsigned int size, struct book new_book){
	struct book *newbook = realloc(collection, sizeof(struct book) * (size + 2));
    if (newbook == NULL) {
        return NULL; // allocating memory did not work
    }

    strcpy(newbook[size].id,new_book.id);
    newbook[size].title = malloc(strlen(new_book.title) + 1);
    strcpy(newbook[size].title,new_book.title);
    newbook[size].author = malloc(strlen(new_book.author) + 1);
    strcpy(newbook[size].author,new_book.author);
    newbook[size].release_date.day=new_book.release_date.day;
    newbook[size].release_date.month=new_book.release_date.month;
    newbook[size].release_date.year=new_book.release_date.year;
    newbook[size+1].title=NULL;
    newbook[size+1].author=NULL;
    return newbook;
}