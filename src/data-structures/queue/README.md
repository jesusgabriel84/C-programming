<!-- Queue -->
## Queue

This program implements a simple queueing system using a linked list. The queue contains names (```strings```) of the members in the queue. The length of the strings is not limited. The items in linked list are stored in following data structures:

```C
struct studentqueue {
    char *name;  // Name of student (dynamically allocated)
    struct studentqueue *next;  // pointer to next student
};
```

As explained before, there is no limitation for the strings length, for this reason, this ```strings``` variable must be assigned in dynamically allocated memory. To facilitate the work with the list, the first element will always be empty, i.e. ```NULL```, and it should not be considered. Then, in the last element of the list the next pointer should be ```NULL```. As a consequence, when the list is empty, both fields are ```NULL``` in the first element.

>This implementation pays attention to the special cases, e.g. the case of an empty list. The data structure and needed function interfaces are defined in file [``queue.h``](queue.h).


### Functions

The program consists of the following two functions:

- **enqueue**:
```C
int enqueue(struct studentqueue *q, const char *name)
```
This function recives a string from the variable ``*name`` and add it to the last item of the list, for this reason it makes two memory allocations: one to expand the size of the data structure (```struct studentqueue```) and a second memory allocation to store the values of the string varible ``*name``.

  The function returns:
   - A value of 1 if addition was successful.
   - A value of 0 if it failed for some reason. For example, a function will fail if there is a memory allocation problem.

- **dequeue**:
```C
int dequeue(struct studentqueue *q, char *buffer, unsigned int size)
```
This function removes the first item from the queue. Take into account that before removing the item, the name stored in there should be saved to a temporary variable, which also needs to be allocated accordingly. If the element is not stored in temporary buffer, then the link list will be incomplete.

  The function returns:
   - A value of 1 if there was an item successfully removed from the list.
   - A value of 0 if nothing was removed from the list.


### Running the program

Execute the following:
```bash
gcc -o main main.c queue.c -Wvla -Wall -g -std=c99
./main
```