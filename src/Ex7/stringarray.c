#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringarray.h"

/* Exercise a: Initializes the string array to contain the initial
 * NULL pointer, but nothing else.
 * Returns: pointer to the array of strings that has one element
 *      (that contains NULL)
 */
char **init_string_array(void)
{
	char **arr;
	
	arr = malloc(sizeof(char *));
	//**arr=NULL;
	//arr[0] = malloc(sizeof(char));
	// didn't work arr[0] = NULL;
	// didn't work arr[0][0] = NULL;
	// didn't work arr[0] = 0;
	// didn't work arr[0][0] = 0;
	// didn't work arr[0]=NULL;
	// didn't work *arr[0]=NULL;
	arr[0]=NULL;
	return arr;
}

/* Releases the memory used by the strings.
 */
void release_string_array(char **arr)
{
	int ydim;
	for (ydim = 0; arr[ydim] != NULL; ydim++);
	//for (int j = 0; j < strlen(arr[j]); j++) free(arr[j]);
	for (int j = 0; j < ydim; j++) free(arr[j]);
    free(arr);
}

/* Exercise b: Add <string> to the end of array <array>.
 * Returns: pointer to the array after the string has been added.
 */
char **insert_string(char **arr, const char *str)
{
	int i;
	for ( i = 0; arr[i] != NULL; i++);
	//arr = (char**)realloc(arr, (i+2)*sizeof(char *));
	arr = realloc(arr, (i+2)*sizeof(char *));
	arr[i] = malloc((strlen(str)+1) * sizeof(int));
	strncpy(arr[i],str,strlen(str)+1);
	arr[i+1]=NULL;
	return arr;
}


/* Exercise c: reorder strings in <array> to lexicographical order */
void sort_string_array(char **arr)
{
	int ydim;
	for (ydim = 0; arr[ydim] != NULL; ydim++);
	//int xdim = strlen(arr[0]);
	//char *temp=malloc(50*sizeof(char));
	char temp[50];
	for(int i=0; i<ydim-1; ++i)
        for(int j=i+1; j<ydim ; ++j)
        {
            if(strcmp(arr[i], arr[j])>0)
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    //free(temp);
}

/* You can use this function to check what your array looks like.
 */
void print_string_array(char **arr)
{
    if (!arr)
        return;
    while (*arr) {
        printf("%s  ", *arr);
        arr++;
    }
    printf("\n");
}