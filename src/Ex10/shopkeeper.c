#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shopfunctions.h"

/* Compare two strings lexically (ASCII value-wise, same as strcmp())
 * The string "duck" is before "rabbit" in this order but
 *  "Rabbit" is before "duck" (see an ASCII chart)
 * Returns: 0 if the two strings are equal
 * Hint: strcmp
 */
int compareAlpha(const void* a, const void* b)
{
    const Product *prod1 = a;
    const Product *prod2 = b;

    // Return the result of strcmp
    return strcmp(prod1->name, prod2->name);
}

/* Same as compareAlpha but compares the product *in_stock* numerically.
 * The product with higher *in_stock* -value should be first in the array.
 * If there are two or more products with same *in_stock* -value, they are compared lexically.
 */
int compareNum(const void* a, const void* b)
{
	const Product *prod1 = a;
    const Product *prod2 = b;

    if(prod2->in_stock!=prod1->in_stock) 
    {
    	return prod2->in_stock-prod1->in_stock;
    }
    else
    {
	    //If both stocks are equal, then we order lexically
		return strcmp(prod1->name, prod2->name);
	}

}

/* Finds a product from a sorted array of products
 * Returns: Whatever bsearch returned.
 * IMPORTANT: Remember that bsearch takes a pointer to a type as first parameter, and 
 * pointer to an array with same type elements as in first parameter.
 */
Product* findProduct(Product* p_array, const char* searchkey, int (*cmp)(const void*, const void*))
{
	//Calculate the number of elements in the Product array
	int count = 0;
	int i = 0;
	while(strcmp(p_array[i].name,"\0")!=0) //(NOTICE!!!) =>Need to use strcmp because we have to compare with string "\0" not with value '\0'
		{
			count++;
			i++;
		}
	count++;

	//Creating the Product search key with name = searchkey
	Product searchprod;
	strcpy(searchprod.name, searchkey);
	searchprod.price = 0;
	searchprod.in_stock = 0;

	//Searching the Product variable on the array
	Product *prod = (Product *)bsearch(&searchprod,p_array,count,sizeof(Product),cmp);
	return prod;
}