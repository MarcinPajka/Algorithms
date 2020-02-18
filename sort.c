#include "sort.h"
#include "misc.h"
#include<stdlib.h>
bool less(int a,int b)
{
  if( a > b )
    return false;
  else
    return true;
}
void exch(int * tab,int i,int j)
{
  int tmp_val = tab[i];
  tab[i] = tab[j];
  tab[j] = tmp_val;
}
void selection(int * table,int N, int plot)
{
  for( int i = 0; i < N; i++)
  {
    int min = i;
    for( int j = i; j < N; j++)
    {
      if( less(table[j], table[min]) )
        min = j;
    }
    exch(table, i, min); 
    if (plot)
      gnuplot_save_table_data(table,N,i);  
  }
}
