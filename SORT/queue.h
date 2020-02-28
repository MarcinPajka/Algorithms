#include<vector>
#define MAX_VAL 250

template<class T>
class Queue
{
  unsigned int N;
  unsigned int size;
  std::vector<T> v;
  bool is_empty();
  void exch(long  int i,long int j);
  bool less(T a, T b);

  public: 
  void swim(unsigned int k);
  void sink(unsigned int k);
  void insert(T val);
  void delMax();
  void sort();
  void set_data( int N);
};
