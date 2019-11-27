#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int print_file_and_count(const char *filename)
{
	int c;
	int number = 0;
	FILE* f = NULL;

    /* Open file */
    f = fopen(filename, "r");

    if (NULL != f)
    {
        while ((c = fgetc(f)) !=EOF)
        {
        	fprintf(stdout,"%c",c);
        	number++;
    	}
        fclose(f);
        return number;
    }
    else
    {
        return -1;
    }
}

char *difference(const char* file1, const char* file2)
{
	char ch1[1000],ch2[1000];


	//Openning the files:
	FILE * f1 = fopen (file1, "rb");
	FILE * f2 = fopen (file2, "rb");
	fgets(ch1,1000,f1);
    fgets(ch2,1000,f2);
    while(ch1!=NULL && ch2!=NULL)
    {
	    if(strcmp(ch1, ch2)!=0)
	    {
	    	//What is the difference between calloc and malloc
	    	char *temp = calloc(strlen(ch1)+6+strlen(ch2)+1,1);
	    	strcat(temp,ch1);
	    	strcat(temp, "----\n");
	    	strcat(temp, ch2);
	    	return temp;
	    }
	    fgets(ch1,1000,f1);
    	fgets(ch2,1000,f2);
	}
	return NULL;
}