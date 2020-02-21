#include "sort.h"
#include "misc.h"
#include "../PQ/pq.h"



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
void selection(int * table,int N)
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
  }
}
void insertion(int * table,int N)
{
  for( int i = 1; i < N; i++)
  {
    for( int j = i; j > 0 && less(table[j], table[j-1]) ; j--)
      exch(table, j, j-1);       
  }
}

void shell(int * table, int N)
{
  int h = 1;
  while( h < N/3 )
    h *=3;
  while( h >= 1)
  {
    for(int i = h; i < N; i++)
    {
      for(int j = i; j >= h && less(table[j], table[j-h]); j -=h  )
        exch(table, j, j-h);       
    }
    h = h/3;
  }

}

void merge_sort__merge(int * table, int lo,int mid, int hi)
{
  int i = lo;
  int j = mid+1;
  int aux[hi];
  for(int k = lo; k <= hi; k++)
    aux[k] = table[k];
  
  for(int k = lo; k <= hi; k++)
  {
    if(i > mid)
      table[k] = aux[j++];
    else if(j > hi)
      table[k] = aux[i++];
    else if( less(aux[j],aux[i]) )
      table[k] = aux[j++];
    else
      table[k] = aux[i++]; 
  }
}

void merge_sort__sort(int * table, int lo, int hi)
{
  if(hi <= lo)
    return;
  int mid = lo + (hi-lo)/2;
  merge_sort__sort(table,lo,mid);
  merge_sort__sort(table,mid+1,hi);
  merge_sort__merge(table,lo,mid,hi);
  
}
void merge_sort(int * table, int N)
{
  merge_sort__sort(table,0,N-1);
}
void merge_sort_BU(int * table, int N)
{
  for(int sz = 1; sz < N; sz = sz+sz)
  {  
    for(int lo = 0; lo < N-sz; lo +=sz+sz)
      merge_sort__merge(table,lo,lo+sz-1,MIN(lo+sz+sz-1,N-1));
  } 
}

void quick__sort(int * table, int lo, int hi)
{
  if(hi <= lo )
    return;  
  
  int j = quick__partition(table,lo,hi);

  quick__sort(table,lo,j-1);
  quick__sort(table,j+1,hi);

}
void quick_3way__sort(int * table, int lo, int hi)
{
  if(hi <= lo )
    return;  
  int lt = lo;
  int i = lo + 1;
  int gt = hi;
  int v = table[lo];

  while( i <= gt)
  {
   
    if ( table[i] > v )
      exch(table, i, gt--);
    else if(table[i] < v )
      exch(table,lt++,i++);
    else 
      i++;
  }  

  quick_3way__sort(table,lo,lt-1);
  quick_3way__sort(table,gt+1,hi);

}

int quick__partition(int * table,int lo, int hi)
{
  int i = lo;
  int j = hi + 1;
  int v = table[lo];
  while(1)
  {
    while( less(table[++i],v) && i - hi != 0 );
    while( less(v,table[--j]) && j - lo != 0 );
    if( i >= j)
      break;
    exch(table,i,j);
  } 
  exch(table,lo,j);
  return j;
}
void quick(int * table, int N)
{
  quick__sort(table,0,N-1);
}
void quick_3way(int * table, int N)
{
  quick_3way__sort(table,0,N-1);
}
void is_sorted(int * table, int N)
{
  for(int i = 0; i < N-1; i++)
  {
    if (table[i] > table[i+1] )
    {
      printf("\nTable not sorted\n");
      return;
    }  
  }
  printf("\nTable sorted\n");
}

int sort(int *table, int N,char * sort_name  )
{
  int timer = clock();
  if( strcmp(sort_name,"Selection") == 0)
  {
    timer = clock();
    selection(table,N); 
    timer = clock() - timer; 
  } 
  else if( strcmp(sort_name,"Insertion") == 0)
  {
    timer = clock();
    insertion(table,N);
    timer = clock() - timer;
  }
  else if( strcmp(sort_name,"Shell") == 0)
  { 
    timer = clock(); 
    shell(table,N);
    timer = clock() - timer;  
  } 
  else if( strcmp(sort_name,"Merge") == 0)
  {  
    timer = clock(); 
    merge_sort(table,N);
    timer = clock() - timer;
  }  
  else if( strcmp(sort_name,"Merge_BU") == 0 )
  {
    timer = clock();
    merge_sort_BU(table,N);
    timer = clock() - timer;
  }
  else if( strcmp(sort_name,"Quick") == 0 )
  {
    timer = clock();
    quick(table,N);
    timer = clock() - timer;
  }
  else if( strcmp(sort_name,"Quick_3way") == 0 )
  {
    timer = clock();
    quick_3way(table,N);
    timer = clock() - timer;
  }
  else if( strcmp(sort_name,"PQ") == 0 )
  {
    timer = clock();
    quick_3way(table,N);
    timer = clock() - timer;
  }
  else
  { 
    printf("Wrong sort type");
    return 0;
  }
  //is_sorted(table,N);    
  return timer;
}
 
