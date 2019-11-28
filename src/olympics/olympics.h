
#ifndef OLYMPICS
#define OLYMPICS

typedef struct {
	char name[20];
	int gold;
	int silver;
	int bronze;
} Nation;

//Support functions:
int find_nation(Nation* p_array, const char* searchkey, int len);
char *get_nation(char *str);
long *get_medals(char *str);
int compareNum(const void* a, const void* b);
int line_count(char *filename);

//Project functions:
Nation *add_nation(Nation *db, unsigned int size, const char *p_nation);
void update_medals(Nation* p_array, char* searchkey, int len, long *new_medals);
void print_table(Nation *p_array, int len);
void save_table(Nation *p_array,char *file,int len);
Nation *open_file(char *filename);


#endif /* PROJECT_FUNCTIONS */