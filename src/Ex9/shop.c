#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aaltoshop.h"

int output_binary(const char* filename, Product* shop)
{
	FILE *f;
	int n;
	n = sizeof(shop);
	f = fopen(filename,"wb");  // w for write, b for binary


	if(f!=NULL)
	{
		for(int i=0;i<n-1;i++)
		{
			fwrite(&shop[i],sizeof(Product),1000,f); 
		}
		fclose(f);
		return 0;
	}
	else
	{
		fclose(f);
		return 1;
	}
	
}

Product* read_binary(const char* filename)
{
	//Product *prod = malloc(sizeof(Product));
	return NULL;
}

int output_plaintext(const char* filename, Product* shop)
{
	/*int count = 0;
	FILE * f;
  
	f = fopen (filename,"w");
	if(f!=NULL)
	{
		while(count<5)
		{
			fprintf(f,"%s ",shop->name);
			fprintf(f,"%f ",shop->price);
			fprintf(f,"%d\n",shop->in_stock);
			shop++;
			count++;
		}
		printf("counter: %d\n",count);
		fclose(f);
		return 0;
	}
	else
	{
		fclose(f);
		return 1;
	}*/
	return 1;
}

Product* read_plaintext(const char* filename)
{
	//Product *prod = malloc(sizeof(Product));
	return NULL;
}