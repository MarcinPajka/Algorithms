#include "sort.h"
#include "misc.h"

int main(void)
{ 
  int N = 10;
  int * table[N];
  int sizes[] = {100,500,1000,2500,5000,6000,7000,8000,9000,10000 };
  generate_and_fill_tables(table,sizes,N);
  

  selection(table[0],sizes[0],1);
  gnuplot_create_animation("tmp_chart",99);
  long int timer = clock();  timer = clock(); 

  for(int i = 0 ; i < N ; i++)
  { 
    selection(table[i],sizes[i],0);
    printf("Selection sort, data size: %-7d cycles:  %ld \n",sizes[i], clock() - timer );
    timer = clock(); 
  } 

  free_tables(table, N);
  return 0;
}
