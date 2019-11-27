#include <stdlib.h>
#include <stdio.h>

int file_to_hex(const char *filename){
	int nbytes = 0;
	int c;
	int pos = 0;
	FILE* f = NULL;

    /* Open file */
    f = fopen(filename, "r");

    if (NULL != f)
    {
        while ((c = fgetc(f)) !=EOF)
        {
        	printf("%02x ",c); //Print integer as decimal with 2 hex values
        	nbytes++; //count the number of bytes
        	pos++;
        	//Change line every 16 elements
        	if(pos==16)
        	{
        		printf("\n");
        		pos=0;
        	}
    	}
        fclose(f);
        return nbytes;
    }
    else
    {
        return -1;
    }
    
}