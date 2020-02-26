#include "sort.h"

int main()
{ 

  vector<long> sizes{10,100,1000,10000,100000};
  Sort<double> sort;
  vector<chrono::duration<double>> time(sizes.size());

 
  sort.selection(1);

  return 0;
}
