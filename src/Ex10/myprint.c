#include<stdio.h> 
#include<stdarg.h>                      


int myprint(const char* str,...) 
{ 
    //char *traverse; 
    int i; 
    int counter = 0;

    //Module 1: Initializing Myprintf's arguments 
    va_list arg; 
    va_start(arg, str); 

    while(*str != '\0')
    { 
        while( *str != '&' ) 
        { 
            putchar(*str);
            str++; 
        } 
        i = va_arg(arg,int);     //Fetch char argument
        counter++;
        printf("%d",i);
        //putchar(i);
        str++;
    } 

    //Module 3: Closing argument list to necessary clean-up
    va_end(arg); 
    return counter;
} 