#include<vector>
#include<cstdlib>
#include<iostream>
#include<chrono>

#define MAX_VAL 100
#define MIN(a,b) ( ((a) > (b)) ? b : a )
using namespace std;

template<class T>
class Sort
{
  vector<T> v; 
  bool less(T a, T b);
  void is_sorted(void);
  void exch(vector<T> tab,long  int i,long int j);
  void randomize_data(void);
  void resize(long int N);
  public:
  int selection(long int N);
  chrono::duration<double> insertion(long int N);

};
