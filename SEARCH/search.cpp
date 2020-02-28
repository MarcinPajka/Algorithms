#include "search.h"

template<class Key, class Val>
int BinarySearch<Key,Val>::size()
{
  return N;
}

template<class Key, class Val>
Val BinarySearch<Key,Val>get(Key key)
{
  if (N == 0)
    return;
  int i = rank(key);
  if (i < N && keys[i] == key)
    return vals[i];
  else
    return;
}

template<class Key, class Val>
int BinarySearch<Key,Val>::rank(T key)
{
  int lo = 0; hi = N-1;

  while (lo <= hi)
  {
    int mid = lo + (hi - lo) / 2;
    if (key > keys[mid])
      lo = mid + 1;
    else if (key < keys[mid])
      hi = mid - 1;
    else 
      return mid; 
  }
  return lo;
}

template<class Key, class Val>
void BinarySearch::put(Key key, Val val)
{
  int i = rank(key);
  if (i < N && keys[i] == key)
  {
    vals[i] = val;
    return;
  }
  keys.push_back(keys[N-1]);
  vals.push_back(vals[N-1]);
  for (int j = N-1; j > i; j--)
  {
    keys[j] = keys[j-1];
    vals[j] = vals[j-1];
  }
  keys[i] = key;
  vals[i] = val;
  N++;
}
