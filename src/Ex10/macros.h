#define EQ3(a,b,c) ({(a == b ? (a == c ? 1: 0): 0);})
#define MIN3(a,b,c) ({(a > b) ? (b > c ? c : b) : (a > c ? c: a);})