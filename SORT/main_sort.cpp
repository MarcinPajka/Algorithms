#include "sort_template.h"
#include "matplotlibcpp.h"

#define SORTS 2
int main()
{ 
  

  std::vector<long> sizes{10,100,500,1000,5000,10000,15000,20000,25000,30000,35000,40000,45000,50000};
  Sort<int> sort;
  std::vector< std::vector<double> > time(SORTS);
  std::chrono::duration<double> seconds; 

  for (unsigned int i = 0; i < sizes.size(); i++)
  {
    sort.resize(sizes.at(i));
    

    std::cout<<std::endl<<"table size: " <<sizes.at(i)<<std::endl;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();  

    sort.selection();

    end = std::chrono::system_clock::now();   
    seconds = end - start; 
    std::cout<<"SELECTION SORT Time: "<< seconds.count() <<std::endl;
    time[0][i] = seconds.count();   

    start = std::chrono::system_clock::now();   
    
    sort.insertion();
    
    end = std::chrono::system_clock::now();   
    seconds = end - start; 
    std::cout<<"INSERTION SORT Time: "<< seconds.count() <<std::endl;

    time[1][i] = seconds.count();
  } 

 
  namespace plt = matplotlibcpp;
  plt::plot({1,2,3,4});
  plt::show();

  return 0;
}
