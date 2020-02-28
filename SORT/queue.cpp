#include "queue.h"

template<class T>
bool Queue<T>::less(T a, T b)
{
  if (a > b)
    return false;
  else
    return true;
}

template<class T>
bool Queue<T>::is_empty()
{
  return N == 0;
}

template<class T>
void Queue<T>::swim(unsigned int k)
{
  while (k > 1 && less(k / 2, k))
  {
    exch(k / 2,k);
    k = k / 2;
  }
}

template<class T>
void Queue<T>::sink(unsigned int k)
{
  while (2 * k <= size)
  {
    unsigned int j = 2 * k;
    if (j < size && less(j,j+1))
      j++;
    if (!less(k,j))
      break;
    exch(k,j);
    k = j;
  }
}

template<class T>
void Queue<T>::exch(long int i,long int j)
{ 
  int tmp_val = v.at(i);
  v.at(i) = v.at(j);
  v.at(j) = tmp_val;
}


template<class T>
void Queue<T>::insert(T val)
{
  v.at(--size) = val;
  swim(size);
}

template<class T>
void Queue<T>::delMax()
{
  T max = v.at(1);
  exch(1,size--);
  v.pop_back();
  sink(1);
  return max;
}

template<class T>
void Queue<T>::sort()
{
 
  unsigned int N = size-1;
  for (int k = N / 2; k >= 1; k--)
    sink(k);
  while (N > 1)
  {
    exch(1, N--);
    sink(1);
  }
}

template<class T>
void Queue<T>::set_data( int N)
{
  v.resize(N + 1);
  size = N; 
  srand(std::time(NULL));
  std::for_each(v.begin(), v.end(), [](int &val){ val = rand() % MAX_VAL;} );
}
