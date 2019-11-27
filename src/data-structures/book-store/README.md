<!-- Book -->
## Book store

Practice the use of dynamically reserved and resizable tables of data structure elements. In this program, I create a simple database for storing books. Each record in the database follows the ```struct book``` structure, and the database consists of a dynamically allocated table, which has several ```struct book``` instances in a row. Whenever a new item is added to a table, it must be ensured that the table has enough memory to store the new item.

>```struct book```- Definition and descriptions of the fields can be found in the file [``book.h``](src/data-structures/book-store/book.h). When defining the data structure, take into account which fields get the space they need as part of the data structure, and which fields need to be reserved separately. In this case, the author and title fields are strings for which it is needed to dynamically allocate the space required.

Following the structs created for the program:

- Date:
```C
// Date in numeric format
struct date {
    unsigned char day;
    unsigned char month;
    int year;
};
```

- Book:
```C
// Single book entry
struct book {
	char id[10];
	char *title;
	char *author;
	struct date release_date;
};
```