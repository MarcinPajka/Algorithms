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
    cout<<endl<<" Data sorted "<<endl;
  else
    cout<<endl<<" Data not sorted "<<endl;
  

  return sorted;   
}

template<class T>
void Sort<T>::exch(vector<T> tab,long int i,long int j)
{ 
  int tmp_val = tab.at(i);
  tab.at(i) = tab.at(j);
  tab.at(j) = tmp_val;
}

template<class T>
void Sort<T>::randomize_data(void)
{
  for_each(v.begin(), v.end(), [](int &val){ val = rand() % MAX_VAL;} );
}

template<class T>
void Sort<T>::resize(long int  N)
{
  if ( N != v.size())
    v.resize(N);
}

template<class T>
int Sort<T>::selection(long int N)
{
  resize(N);
  randomize_data();

  cout<<endl<<"SELECTION sort"<<endl;
  chrono::time_point<chrono::system_clock> start, end;
  start = chrono::system_clock::now();  

  for (int i = 0; i < v.size(); i++)
  {
    T min = i;
    for (int j = i; j < v.size(); j++)
    {
      if (less(v.at(j), v.at(min)))
        min = j;
    }
    exch(v, i, min); 
  }

  end = chrono::system_clock::now();   
  chrono::duration<double> seconds = end - start; 
  cout<<"Time: "<< seconds.count() <<endl;

  return seconds;
}

template<class T>
chrono::duration<double> Sort<T>::insertion(long int N)
{
  resize(N);
  randomize_data();

  cout<<endl<<"INSERTION sort, table size: "<<v.size()<<endl;
  chrono::time_point<chrono::system_clock> start, end;
  start = chrono::system_clock::now();   
 
  for (int i = 1; i < v.size(); i++)
  {
    for (int j = i; j > 0 && less(v.at(j), v.at(j-1)) ;j--)
      exch(v, j, j-1);       
  }
  end = chrono::system_clock::now();   
  chrono::duration<double> seconds = end - start; 
  cout<<"Time: "<< seconds.count() <<endl;

  return seconds;
}


