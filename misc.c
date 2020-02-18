#include "misc.h"
void fill_table(int * table, int N)
{
  srand(time(0));
  
  for( int i = 0; i < N; i++)
  {
    table[i] = rand() % 501;
  }
}


