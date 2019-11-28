<!-- game-of-life -->
## Game of Life

This program implements the classic Conway’s [*Game of Life*](http://en.m.wikipedia.org/wiki/Conway%27s_Game_of_Life) allocating and manipulating dynamic two-dimensional arrays. The Game of Life operates on a two-dimensional world, which is a grid consisting of cells that can have only two possible states: either *``dead``* or *``alive``*, in this sense, the *world* changes on every iteration by updating the state of every cell on it, and the state of a particular cell depends on its neighbors, i.e. the state of the cells surrounding it.

The cell's state changes according to the following rules:

* Any **live** cell with **less than two live** neighbours **dies**.

* Any **live** cell with **two or three live** neighbours **lives** on to the next generation.

* Any **live** cell with **more than three live** neighbours **dies**.

* Any **dead** cell with **exactly three live** neighbours becomes a **live** cell.


>Also the cells that are in the corners (i.e. diagonal cells) are neighbors, then each cell will have as a maximum of 8 neighbors

For instance, this would be the evolution of the game area on each generation (each iteration), being the symbol ``*`` the representation of an alive cell:

```bash
Generation: 1
*..*..***..**.....*.
.....**.*...........
..........*.*..**...
...*..**..........*.
.*.........*.*..**.*
*.........*.........
.........**.*.*.....
.*....*...*.....*...
..*...*.*...*...*...
**..*.*....****.....
```

Ànd a following generation would be:

```bash
Generation: 2
.....**.*...........
.....**.**..*.......
.....*..............
...........**..*..*.
.................**.
.........**.**......
.........**.........
.......*..*..*.*....
*.*...*.....*..*....
.*...*.*...***......
```

The following ``structs`` are defined to implement the program:

```C
typedef enum {
    DEAD,
    ALIVE
} CellStatus;

typedef struct {
    unsigned int x_size, y_size;
    CellStatus **cells;
} GameArea;
```

### Functions

The program consists of the following functions:

- **createGameArea**:
```C
GameArea *createGameArea(unsigned int x_size, unsigned int y_size)
```

This function allocates the required memory space for the GameArea structure that will contain the game area, and for a two-dimensional array of dimensions given in parameters ``x_size`` and ``y_size``. Each cell in the area must be initialized to ``DEAD`` status, as well as the ``x_size`` and ``y_size`` areas in the structure.

>**Note**: In this implementations the pointers to the rows (y-axis) of the game area grid are the first dimension of the array and the columns (x-axis) correspond to the second dimension. For this reason the cells are indexed as ``[y][x]``.


- **releaseGameArea**:
```C
void releaseGameArea(GameArea *a)
```
This function releases the memory allocated by the previous function.


- **initGameArea**:
```C
void initGameArea(GameArea *a, unsigned int n)
```
This function turns the number of cells defined by the user as ``ALIVE`` in a random fashion.


- **printGameArea**:
```C
void printGameArea(const GameArea *a)
```
This function outputs to ``stdout`` the current status of the game area grid:
 - The cell with the symbol ``*`` represents an ``ALIVE`` cell.
 - The cell with the symbol ``.`` represents a ``DEAD`` cell.


- **gameTick**:
```C
void gameTick(GameArea *a)
```
This function advances the game area grid in one generation based on the [**rules**](#game-of-life). The cells in the game area are evaluated all simultaneously.


### Running the program

Execute the following:
```bash
gcc -o main main.c gameoflife.c -Wvla -Wall -g -std=c99
./main
```