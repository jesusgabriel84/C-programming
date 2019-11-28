<!-- olympics -->
## Olympics

This program implements a simple database of medals from countries. The program has the following characteristics:

* Read list of countries from a file.
* Save the list of countries into a file.
* Shows the list of countries on memory.
* Modify entries in the data base using the country name as the key.

Welcome screen and usage instructions are as follows:

```C
******************************************************
Use the following syntax to create/add countries:
- Add nation example: 'A Some_Country' 
- Modify nation example: 'M Some_Country 1 2 3' 
(1: # gold medals, 2: # silver and 3: # bronze medals)
- 'L': Prints the current country database
- Save database example: 'W file_name.txt' 
- Open database example: 'O file_name.txt' 
- Exit: 'Q' 
******************************************************
Enter command: 
```

### Running the program

Execute the following:
```bash
gcc -o main olympics.c -Wvla -Wall -g -std=c99 
./main
```
