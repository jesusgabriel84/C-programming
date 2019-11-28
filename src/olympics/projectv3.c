/**************************************
**Author:     Jesus Gabriel Ly Ponce **
**Student ID: 722456                 **
***************************************
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "project.h"

//Support functions:
//------------------

//Return 0 if the searchkey is in the data base, otherwise return -1
int find_nation(Nation* p_array, const char* searchkey, int len)
{
    for(int i=0;i<len;i++)
    {
        if(strcmp(p_array[i].name,searchkey)==0) return 0;
    }
    return -1;
}

//Extract the country name from the command line considering also that the country may have blank spaces
char *get_nation(char *str)
{
    int i=0;

    while (str[i]!=0) {
        if (isdigit(str[i])) {
            if(str[i-1]=='-')
            {
                i--;
            }
            break;

        } else {
            i++;
        }
    }

    char *new_str = calloc((i+1),sizeof(char));
    memmove(&new_str[0],&str[2],i-2);
    new_str[strlen(new_str)-1]='\0';
    if(isalpha(new_str[strlen(new_str)-1])==0) new_str[strlen(new_str)-1]='\0'; //Ensuring there aren't non-alphabet characters
    return new_str;
}

//Extract the medals from the command line and store the values in an array of 'long'
long *get_medals(char *str)
{
    static long new_medals[]={0,0,0};
    int i=0;
    char *ptr = str;

    while (*ptr) {
        if (isdigit(*ptr)) {
            if(*(ptr-1)=='-')
            {
                new_medals[i] = (-1)*strtol(ptr, &ptr, 10);
            }
            else
            {
                new_medals[i] = strtol(ptr, &ptr, 10);
            }
            i++;
        } else {
            ptr++;
        }
    }

    return new_medals;
}

//Compare the number of medals:
int compareNum(const void* a, const void* b)
{
    const Nation *n1 = a;
    const Nation *n2 = b;

    if(n2->gold!=n1->gold) 
    {
        return n2->gold-n1->gold;
    }
    if(n2->silver!=n1->silver) 
    {
        return n2->silver-n1->silver;
    }
    if(n2->bronze!=n1->bronze) 
    {
        return n2->bronze-n1->bronze;
    }
    else
    {
        //If all medals count are equal, then we order lexically
        return strcmp(n1->name, n2->name);
    }

}

//Count lines in file:
int line_count(char *filename)
{
    int lines = 0;
    char c;

    //Openning the files:
    FILE * f = fopen (filename, "r");

    if (f==NULL) {
        return 0;
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
        fclose(f);   
        return lines;
    }
}


//**************************
//*FUNCTIONS OF THE PROJECT*
//**************************

//a) Add Nation function:
Nation *add_nation(Nation *db, unsigned int size, const char *p_nation)
{
    Nation *new_db = realloc(db, sizeof(Nation) * (size + 2));
    if (new_db == NULL) {
        return NULL; // allocating memory did not work
    }

    strcpy(new_db[size].name,p_nation);
    new_db[size].gold=0;
    new_db[size].silver=0;
    new_db[size].bronze=0;
    strcpy(new_db[size+1].name,"\0");
    return new_db;
}

//b) Update medals:
void update_medals(Nation* p_array, char* searchkey, int len, long *new_medals)
{
    for(int i=0;i<len;i++)
    {
        if(strcmp(p_array[i].name,searchkey)==0)
        {
            p_array[i].gold=new_medals[0]+p_array[i].gold;
            p_array[i].silver=new_medals[1]+p_array[i].silver;
            p_array[i].bronze=new_medals[2]+p_array[i].bronze;
        }
    }
}


//c) Output medal table:
void print_table(Nation *p_array, int len)
{
    //Printing the table header:
    int j;
    for(j=0;j<37;j++)
    {
        printf("-");
    }
    printf("\n");
    printf("|Country             |Gol |Sil |Bro |\n");
    for(j=0;j<37;j++)
    {
        printf("-");
    }
    printf("\n");

    //Printing the country names:
    for ( int i = 0; i < len; i++) 
    {
      printf("|%s",p_array[i].name);
      if(strlen(p_array[i].name)<20)
      {
        for(int j=1;j<=20-strlen(p_array[i].name);j++)
        {
            printf(" ");
        }
      }

      //Printing the gold medals considering the sign of the number of medals:
      if(p_array[i].gold<0)
      {
        if(p_array[i].gold>-10)
          {
            printf("|  %d",p_array[i].gold);
          }
          if(p_array[i].gold<-9 && p_array[i].gold>-100)
          {
            printf("| %d",p_array[i].gold);
          }
          if(p_array[i].gold<-99)
          {
            printf("|%d",p_array[i].gold);
          }
      }
      else
      {
          if(p_array[i].gold<10)
          {
            printf("|   %d",p_array[i].gold);
          }
          if(p_array[i].gold>9 && p_array[i].gold<100)
          {
            printf("|  %d",p_array[i].gold);
          }
          if(p_array[i].gold>99)
          {
            printf("| %d",p_array[i].gold);
          }
      }

      //Printing the silver medals considering the sign of the number of medals:
      if(p_array[i].silver<0)
      {
        if(p_array[i].silver>-10)
          {
            printf("|  %d",p_array[i].silver);
          }
          if(p_array[i].silver<-9 && p_array[i].silver>-100)
          {
            printf("| %d",p_array[i].silver);
          }
          if(p_array[i].silver<-99)
          {
            printf("|%d",p_array[i].silver);
          }
      }
      else
      {
          if(p_array[i].silver<10)
          {
            printf("|   %d",p_array[i].silver);
          }
          if(p_array[i].silver>9 && p_array[i].silver<100)
          {
            printf("|  %d",p_array[i].silver);
          }
          if(p_array[i].silver>99)
          {
            printf("| %d",p_array[i].silver);
          }
      }

      //Printing the bronze medals considering the sign of the number of medals:
      if(p_array[i].bronze<0)
      {
        if(p_array[i].bronze>-10)
          {
            printf("|  %d|\n",p_array[i].bronze);
          }
          if(p_array[i].bronze<-9 && p_array[i].bronze>-100)
          {
            printf("| %d|\n",p_array[i].bronze);
          }
          if(p_array[i].bronze<-99)
          {
            printf("|%d|\n",p_array[i].bronze);
          }
      }
      else
      {
          if(p_array[i].bronze<10)
          {
            printf("|   %d|\n",p_array[i].bronze);
          }
          if(p_array[i].bronze>9 && p_array[i].bronze<100)
          {
            printf("|  %d|\n",p_array[i].bronze);
          }
          if(p_array[i].bronze>99)
          {
            printf("| %d|\n",p_array[i].bronze);
          }
      }

    //Printing the end of the table
    }
    for(j=0;j<37;j++)
    {
        printf("-");
    }
    printf("\n");
}


//d) Save table into file:
void save_table(Nation *p_array,char *file,int len)
{
    FILE *f;
    f = fopen(file, "w");
    for ( int i = 0; i < len; i++) 
    {
        fprintf(f,"%s;%d;%d;%d\n",p_array[i].name,p_array[i].gold,p_array[i].silver,p_array[i].bronze);
    }
    fclose(f);
}


//e) Open file to save it in new data base:
Nation *open_file(char *filename)
{
    int ii=0;
    FILE *f = fopen(filename,"r");
    char c;
    if (f == NULL) {
        return NULL; // allocating memory did not work
    }
    else
    {
        int lines = line_count(filename);
        Nation *new_db = calloc((lines + 1),sizeof(Nation));


        if (new_db == NULL) {
            return NULL; // allocating memory did not work
        }
        
        for(int j=0;j<lines;j++)
        {
            //Reading the lines from the file and setting the lines to the readable format of my implementation
            //to extract the country name and the number of medals. The format is: 'M <Country name> <gold> <silver> <bronze>'
            char *str = calloc(3,sizeof(char));
            str[0]='M';ii++;
            str[1]=' ';ii++;
            
            //Start going through the file
            c = getc(f);
            while(c!='\n')
            {
                if(c==';')
                {
                    str[ii]=' ';
                }
                else
                {
                    str[ii]=c; 
                }
                
                ii++;
                str = realloc(str, ((ii+1) * sizeof(char)));
                c = getc(f);
            }
            str[ii]='\0'; //Close the string

            //Reading the values to write in the new data base:
            char *nation=get_nation(str);
            long *medals=get_medals(str);

            //Assigning the values read from the file to the new data base:
            strcpy(new_db[j].name,nation);
            new_db[j].gold=medals[0];
            new_db[j].silver=medals[1];
            new_db[j].bronze=medals[2];

            //Release the memory allocated for the next iteration:
            free(str);
            free(nation);
            ii=0;

        }
    fclose(f);
    return new_db;
    }
}


//***************
//*Main program:*
//***************
int main(void)
{
    Nation *db = NULL; //Creating the database
    unsigned int len = 0; //Take the count of the length of the data base
    char str[10000]; //This is the line read from the user input

    //The loop to wait for user command
    while(1)
    {
        fgets(str, 10000, stdin); //Read the line from user input

        if(str[0]=='A')
        {
            char *nation=get_nation(str);

            if(find_nation(db,nation,len)!=0)
            {
                Nation *new_db = add_nation(db, len, nation);
                if (!new_db) 
                {
                    printf("ERROR - New dB is NULL\n");
                    return 1;
                }
                len++;
                db = new_db;
            }
            else
            {
                printf("ERROR - The country: %s already exists\n",nation);
            }
            free(nation);
            continue;
        }

        if(str[0]=='M')
        {
            char *nation=get_nation(str);
            long *medals=get_medals(str);

            if(find_nation(db,nation,len)==0)
            {
                update_medals(db, nation, len, medals);
            }
            else
            {
                printf("ERROR - The country: %s doesn't exist\n",nation);
            }
            free(nation);
            continue;
        }

        if(str[0]=='L') 
        {
            qsort(db, len, sizeof(Nation), compareNum);
            print_table(db,len);
            continue;
        }

        if(str[0]=='W') 
        {
            char *file_name = calloc((strlen(str)+1),sizeof(char));
            memmove(&file_name[0],&str[2],strlen(str)-2);
            file_name[strlen(file_name)-1]='\0';

            //Ensuring there aren't non-alphabet characters
            if(isalpha(file_name[strlen(file_name)-1])==0) file_name[strlen(file_name)-1]='\0'; 

            save_table(db,file_name,len);
            free(file_name);
            continue;
        }

        if(str[0]=='O') 
        {
            char *file_name = calloc((strlen(str)+1),sizeof(char));
            memmove(&file_name[0],&str[2],strlen(str)-2);
            file_name[strlen(file_name)-1]='\0';

            //Ensuring there aren't non-alphabet characters
            if(isalpha(file_name[strlen(file_name)-1])==0) file_name[strlen(file_name)-1]='\0'; 

            Nation *db_new = open_file(file_name);
            if(db_new==NULL)
            {
                printf("ERROR openning file %s\n",file_name);
            }
            else
            {
                free(db);
                db=db_new;
                len=line_count(file_name);
            }
            free(file_name);
            continue;
        }

        if(str[0]=='Q') 
        {
            free(db);
            break;
        }
        //If no option match, inform the user of the error
        printf("ERROR - The command %c does not exist\n",str[0]);
    }
    return 0;
}