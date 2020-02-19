#include<math.h>
#include<stdbool.h>

#define MIN(a,b) ( ((a) > (b)) ? b : a )


bool less(int a, int b);
void exch(int * tab,int i,int j);
void selection(int * table,int N);
void insertion(int * table,int N);
void shell(int * table, int N);
void static merge_sort__merge(int * table, int lo,int mid, int hi);
void static merge_sort__sort(int * table, int lo, int hi);
void merge_sort(int * table, int N);
void merge_sort_BU(int * table, int N);
static void quick__sort(int * table, int lo, int hi);
static void quick_3way__sort(int * table, int lo, int hi);
static int quick__partition(int * table,int lo, int hi);
void quick(int * table, int N);
void quick_3way(int * table, int N);
void is_sorted(int * table, int N);
int sort(int *table, int N,char * sort_name);
