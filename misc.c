#include "misc.h"

void fill_table(int * table, int N)
{
  srand(time(0));
  
  for(int i = 0; i < N; i++)
  {
    table[i] = rand() % 501;
  }
}

void  generate_and_fill_tables(int ** table,int * sizes,int number_of_tables)
{
  for(int i = 0; i < number_of_tables; i++)
  {
    table[i] = (int *)malloc((sizeof(int)) * sizes[i]);
    fill_table(table[i],sizes[i]);
  }  
}

void free_tables(int **table, int N)
{
  for(int i = 0; i < N; i++)
    free(table[i]);
}


