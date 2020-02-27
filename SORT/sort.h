#include<vector>
#include<cstdlib>
#include<iostream>
#include<chrono>
#include<algorithm>
#include<map>

#define MAX_VAL 100000
#define MIN(a,b) ( ((a) > (b)) ? b : a )

template<typename T>
class Sort
{
  std::vector<T> v; 
  bool less(T a, T b);
  void is_sorted(void);
  void exch(std::vector<T> tab,long  int i,long int j);
  void randomize_data(void);

  public:
  void resize(unsigned int N);
  void selection();
  void insertion();
  Sort();

};
