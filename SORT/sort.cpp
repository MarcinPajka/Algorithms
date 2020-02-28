#include "sort.h"

template<class T>
bool Sort<T>::less(T a, T b)
{
  if (a > b)
    return false;
  else
    return true;
}

template<class T>
void Sort<T>::is_sorted(void)
{    
  bool sorted = std::is_sorted(begin(v),end(v)); 
  if (sorted);
    //std::cout<<std::endl<<" Data sorted "<<std::endl;
  else
    std::cout<<std::endl<<" Data not sorted "<<std::endl;
  
}

template<class T>
void Sort<T>::exch(long int i,long int j)
{ 
  int tmp_val = v.at(i);
  v.at(i) = v.at(j);
  v.at(j) = tmp_val;
}

template<class T>
void Sort<T>::merge_merge(int lo, int mid, int hi)
{
  int i = lo, j = mid + 1;
  
  for ( int k = lo; k <= hi; k++)
    aux.at(k) = v.at(k);

  for ( int k = lo; k <= hi; k++)
    if (i > mid)
      v.at(k) = aux.at(j++);
    else if (j > hi)
      v.at(k) = aux.at(i++);
    else if (less(aux.at(j), aux.at(i)))
      v.at(k) = aux.at(j++);
    else
      v.at(k) = aux.at(i++);
}

template<class T>
void Sort<T>::merge_sort(int lo, int hi)
{
  if (hi <= lo)
    return;
  int mid = lo + (hi - lo) / 2;
  merge_sort(lo,mid);
  merge_sort(mid+1,hi); 
  merge_merge(lo,mid,hi);
}
template<class T>
int Sort<T>::quick__partition(unsigned int lo,unsigned int hi)
{
  unsigned int i = lo;
  unsigned int j = hi + 1;
  T val = v[lo];
  while(1)
  {
    while( less(v[++i],val) && i - hi != 0 );
    while( less(val,v[--j]) && j - lo != 0 );
    if( i >= j)
      break;
    exch(i,j);
  } 
  exch(lo,j);
  return j;
}

template<class T>
int Sort<T>::quicksort_with_insert__partition(unsigned int lo,unsigned int hi)
{
  unsigned int i = lo;
  unsigned int j = hi + 1;
  unsigned int k = lo + (lo-hi) / 2;
  T v_1 = v[k-1], v_2 = v[k], v_3 = v[k+1];  
  if (v_2 > v_1)
  {
    if (v_3 > v_2);
    else k = k + 1;
  }
  else
  {
    if (v_1 > v_3) k = k + 1;
    else k = k - 1;
  }
  T val = v[k];
 
  while(1)
  {
    while( less(v[++i],val) && i - hi != 0 );
    while( less(val,v[--j]) && j - lo != 0 );
    if( i >= j)
      break;
    exch(i,j);
  } 
  exch(k,j);
  return j;
}

template<typename T>
void Sort<T>::quicksort_sort(unsigned int lo, unsigned int hi)
{

  if (hi <= lo)
    return;
  unsigned int j = quick__partition(lo,hi);

  quicksort_sort(lo,j );
  quicksort_sort(j + 1,hi);
}

template<typename T>
void Sort<T>::quicksort_with_insert_sort(unsigned int lo, unsigned int hi)
{
  if (hi <= lo + 10)
  {
    for (unsigned int i = lo; i < hi; i++)
    {
      for (int j = i; j > 0 && less(v.at(j), v.at(j-1)) ;j--)
        exch(j, j-1);       
    }
    return;
  }
  unsigned int j = quick__partition(lo,hi);

  quicksort_sort(lo,j );
  quicksort_sort(j + 1,hi);
}

template<typename T>
void Sort<T>::quicksort_3way_sort(int lo ,int hi)
{
  if (hi <= lo)
    return;
  int lt = lo, i = lo+1, gt = hi;
  T var = v[lo];

  while (i <= gt)
  {
    if (v[i] > var)
    {
      exch(lt++,i++);
    }
    else if (v[i] < var)
    {
      exch(i,gt--);
    }
    else
    {
      i++;
    }
  }

  quicksort_3way_sort(lo,lt-1);
  quicksort_3way_sort(gt+1,hi);
}

template<class T>
void Sort<T>::randomize_data(void)
{
  srand(std::time(NULL));
  std::for_each(v.begin(), v.end(), [](int &val){ val = rand() % MAX_VAL;} );
}

template<class T>
void Sort<T>::resize(unsigned int  N)
{
  if ( N != v.size())
    v.resize(N);
    size = N;
}

template<class T>
void Sort<T>::selection()
{

  randomize_data();

  for (unsigned int i = 0; i < size; i++)
  {
    T min = i;
    for (unsigned int j = i; j < size; j++)
    {
      if (less(v.at(j), v.at(min)))
        min = j;
    }
    exch(i, min); 
  }
  is_sorted();

}

template<class T>
void Sort<T>::insertion()
{

  randomize_data();

  for (unsigned int i = 1; i < size; i++)
  {
    for (int j = i; j > 0 && less(v.at(j), v.at(j-1)) ;j--)
      exch(j, j-1);       
  }
  is_sorted();

}

template<typename T>
void Sort<T>::shell()
{
  randomize_data();

  unsigned int h = 1;
  while (h < size/3)
    h = 3 * h + 1;
  while (h >= 1)
  {
    for (unsigned int i = h; i < size; i++)
    {
      for (unsigned int j = i; j >= h && less( v.at(j),v.at(j-h) ); j -= h )
        exch(j, j-h);
    }
    h = h / 3;
  }
}

template<typename T>
void Sort<T>::merge()
{
  randomize_data();
  aux = v;
  merge_sort(0,size - 1);
  is_sorted();
}

template<typename T>
void Sort<T>::merge_BU()
{
  randomize_data();
  aux = v;
  for (unsigned int sz = 1; sz < size; sz = sz + sz)
    for (unsigned int lo = 0; lo < size - sz; lo += sz + sz)
      merge_merge(lo,lo+sz-1,MIN(lo+sz+sz-1,size-1));
  is_sorted();
}

template<typename T>
void Sort<T>::quicksort()
{
  randomize_data();
  quicksort_sort(0,v.size() - 1);
  is_sorted();
}

template<typename T>
void Sort<T>::quicksort_with_insert()
{
  randomize_data();
  quicksort_with_insert_sort(0,v.size() - 1);
  is_sorted();
}

template<typename T>
void Sort<T>::quicksort_3way()
{
  quicksort_3way_sort(0,size-1);
}
