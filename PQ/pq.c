#include "pq.h"

void pq_sort(int * pq, int N)
{ 
  for(int k = N/2; k >= 1; k--)
    sink(pq, &N,k); 
  while( N > 1)
  {
    exch(pq, 1, N);
    N--;
    sink(pq, &N, 1);
  }
}

int is_empty(int N)
{
 return N == 0;
}

void insert(int * pq, int * N, int key)
{
  (*N)++;
  pq[(*N)] = key;
  swim(pq,*N);
}

void swim(int * pq, int key)
{
  while( key > 1 && less(pq[key/2], pq[key]) )
  {
    exch(pq, key/2, key);
    key = key/2;
  }
}

void sink(int * pq, int * N, int key)
{
  while( 2 * key <= (*N) )
  {
    int j = 2 * key;
    if( j < (*N)  && less(pq[j],pq[j+1]) )
      j++;
    if( !less(pq[key],pq[j]) )
      break;
    exch(pq, key, j);
    key = j; 
  }  
}

void delMax(int *pq, int * N)
{
  int max = pq[1];
  exch(pq,1,*N);
  (*N)--;
  pq[(*N) + 1];
  sink(pq, N, 1);
}

