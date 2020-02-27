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
  bool sorted = is_sorted(begin(v),end(v)); 
  if (sorted) 
    std::cout<<std::endl<<" Data sorted "<<std::endl;
  else
    std::cout<<std::endl<<" Data not sorted "<<std::endl;
  

  return sorted;   
}

template<class T>
void Sort<T>::exch(std::vector<T> tab,long int i,long int j)
{ 
  int tmp_val = tab.at(i);
  tab.at(i) = tab.at(j);
  tab.at(j) = tmp_val;
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
}

template<class T>
void Sort<T>::selection()
{
  randomize_data();

  for (unsigned int i = 0; i < v.size(); i++)
  {
    T min = i;
    for (unsigned int j = i; j < v.size(); j++)
    {
      if (less(v.at(j), v.at(min)))
        min = j;
    }
    exch(v, i, min); 
  }
}

template<class T>
void Sort<T>::insertion()
{

  randomize_data();
  for (unsigned int i = 1; i < v.size(); i++)
  {
    for (int j = i; j > 0 && less(v.at(j), v.at(j-1)) ;j--)
      exch(v, j, j-1);       
  }
}

template<typename T>
Sort<T>::Sort()
{
  std::cout<<"Constructor";
}

