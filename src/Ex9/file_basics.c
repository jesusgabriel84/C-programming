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
	char *ch1 = 0; 
    char *ch2 = 0;

	long length1;
	FILE * f1 = fopen (file1, "rb");
	if (f1)
	{
	  fseek (f1, 0, SEEK_END);
	  length1 = ftell (f1);
	  fseek (f1, 0, SEEK_SET);
	  ch1 = malloc (length1);
	  if (ch1)
	  {
	    fread (ch1, 1, length1, f1);
	  }
	  fclose (f1);
	}


	long length2;
	FILE * f2 = fopen (file2, "rb");
	if (f2)
	{
	  fseek (f2, 0, SEEK_END);
	  length2 = ftell (f2);
	  fseek (f2, 0, SEEK_SET);
	  ch2 = malloc (length2);
	  if (ch2)
	  {
	    fread (ch2, 1, length2, f2);
	  }
	  fclose (f2);
	}

    while(ch1 && ch2)
    {
	    char * nextLine1 = strchr(ch1, '\n');
	    int curLineLen1 = nextLine1 ? (nextLine1-ch1) : strlen(ch1);
	    char * tempStr1 =  malloc(curLineLen1+1);

	    char * nextLine2 = strchr(ch2, '\n');
	    int curLineLen2 = nextLine2 ? (nextLine2-ch2) : strlen(ch2);
	    char * tempStr2 =  malloc(curLineLen2+1);

	    memcpy(tempStr1, ch1, curLineLen1);
	    tempStr1[curLineLen1] = '\0';  // NUL-terminate

	    memcpy(tempStr2, ch2, curLineLen2);
	    tempStr2[curLineLen2] = '\0';  // NUL-terminate

	    if(strcmp(tempStr1, tempStr2)!=0)
	    {
	    	strcat(tempStr1, "\n----\n");
	    	strcat(tempStr1, tempStr2);
	    	free(tempStr2);
	    	//free(tempStr1);
	    	free(ch1);
	    	free(ch2);
	    	return tempStr1;
	    }

	    

	    ch1 = nextLine1 ? (nextLine1+1) : NULL;
	    ch2 = nextLine2 ? (nextLine2+1) : NULL;

	}
	free(ch1);
	free(ch2);

	return NULL;
}