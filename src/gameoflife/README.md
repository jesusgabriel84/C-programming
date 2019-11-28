<!-- Game of Life -->
## Game of Life

This program implements the classic Conway’s [*Game of Life*](http://en.m.wikipedia.org/wiki/Conway%27s_Game_of_Life) allocating and manipulating dynamic two-dimensional arrays. The Game of Life operates on a two-dimensional world, which is a grid consisting of cells that can have only two possible states: either *``dead``* or *``alive``*, in this sense, the *world* changes on every iteration by updating the state of every cell on it, and the state of a particular cell depends on its neighbors, i.e. the state of the cells surrounding it.

The cell's state changes according to the following rules:

* Any **live** cell with **less than two live** neighbours **dies**.

* Any **live** cell with **two or three live** neighbours **lives** on to the next generation.

* Any **live** cell with **more than three live** neighbours **dies**.

* Any **dead** cell with **exactly three live** neighbours becomes a **live** cell.


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