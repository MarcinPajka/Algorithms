#include<vector>
#include<cstdlib>
#include<iostream>
#include<chrono>
#include<algorithm>
#include<iomanip>

#define MAX_VAL 250
#define MIN(a,b) ( ((a) > (b)) ? b : a )

template<typename T>
class Sort
{
  unsigned int size;
  std::vector<T> v;
  std::vector<T> aux; 
  bool less(T a, T b);
  void is_sorted();
  void exch(long  int i,long int j);
  void randomize_data();
  void merge_merge(int lo, int mid, int hi);
  void merge_sort(int lo, int hi);
  int  quicksort_with_insert__partition(unsigned int lo,unsigned int hi);
  int  quick__partition(unsigned int lo,unsigned int hi);
  void quicksort_sort(unsigned int lo, unsigned int hi);
  void quicksort_with_insert_sort(unsigned int lo, unsigned int hi);
  void quicksort_3way_sort(int lo, int hi);
  public:
  void resize(unsigned int N);
  void selection();
  void insertion();
  void shell();
  void merge();
  void merge_BU();
  void quicksort();
  void quicksort_with_insert();
  void quicksort_3way();
};
