#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



int line_count(const char *filename)
{
	int lines = 0;
	char c;

	//Openning the files:
	FILE * f = fopen (filename, "r");

	if (f==NULL) {
        return -1;
    }

    else
    {
    	c = getc(f);
    	while(c!=EOF)
    	{
        	lines++;
        	while(c!='\n' && c!=EOF)
        	{
        		c = getc(f);
        	}
        	c = getc(f);
    	}	
		return lines;
	}
}

int word_count(const char *filename)
{
	int words = 0;
	char c;

	//Openning the files:
	FILE * f = fopen (filename, "r");

	if (f==NULL) {
        return -1;
    }

    else
    {
    	c = getc(f);
    	while(c!=EOF)
    	{
	        if(isalpha(c)!=0)
	        {
	        while( isspace(c)==0 && c!=EOF)
	        	{
	        		c = getc(f);
	        	}
	        words++;
	    	}
        	c = getc(f);
    	}



		return words;
	}

}

	
