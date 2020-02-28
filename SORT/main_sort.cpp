#include "sort_template.h"
#define SORTS 9

std::string titles[]{"SELECTION","INSERTION","SHELL","MERGE","MERGE_BU","QUICKSORT","QUICKSORT WITH INSERT","QUICKSORT 3WAY","QUEUE"};
void plot(void);
void print_data(std::string s, double val );

int main()
{ 
  std::vector<long> sizes{10,100,500,1000,2500,5000,7500,10000,12500,15000,17500,20000};
  std::vector<long> sizes_2{10,100,500,1000,5000,7500,10000,12500,15000,17500,20000,22500,25000,27500,30000,32500,35000,37500,40000,42500,45000,
47500,50000,52500,55000,57500,60000};
  Sort<int> sort;
  Queue<int> queue;
  std::vector< std::vector<double> > time(SORTS);
  std::chrono::duration<double> seconds; 
  
 
  for (unsigned int i = 0; i < sizes.size(); i++)
  {
    sort.resize(sizes.at(i)); 

    std::cout<<std::endl<<"table size: "<<sizes.at(i)<<std::endl;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();  

    sort.selection();

    end = std::chrono::system_clock::now();   
    seconds = end - start; 
    std::cout<<"SELECTION SORT Time: "<< seconds.count() <<std::endl;
    time.at(0).push_back(seconds.count());   

    start = std::chrono::system_clock::now();   
    
    sort.insertion();
    
    end = std::chrono::system_clock::now();   
    seconds = end - start; 
    std::cout<<"INSERTION SORT Time: "<< seconds.count() <<std::endl;

    time.at(1).push_back(seconds.count());   
    
    start = std::chrono::system_clock::now();   
    
    sort.shell();
    
    end = std::chrono::system_clock::now();   
    seconds = end - start; 
    std::cout<<"SHELL SORT Time:     "<< seconds.count() <<std::endl;
    time.at(2).push_back(seconds.count());  

 }

for (unsigned int i = 0; i < sizes_2.size(); i++)
  {
    sort.resize(sizes_2.at(i)); 
    std::cout<<std::endl<<"table size: "<<sizes_2.at(i)<<std::endl;
    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();     
    sort.merge();    
    end = std::chrono::system_clock::now();   
  
    seconds = end - start; 
    print_data("MERGE SORT Time: ",seconds.count());
    time.at(3).push_back(seconds.count()); 

    start = std::chrono::system_clock::now();    
    sort.merge_BU();  
    end = std::chrono::system_clock::now();   
 
    seconds = end - start; 
    print_data("MERGE_BU SORT Time: ",seconds.count());
    time.at(4).push_back(seconds.count()); 

    start = std::chrono::system_clock::now();      
    sort.quicksort();   
    end = std::chrono::system_clock::now();   
  
    seconds = end - start; 
    print_data("QUICKSORT SORT Time: ",seconds.count());
    time.at(5).push_back(seconds.count()); 

    start = std::chrono::system_clock::now();    
    sort.quicksort_with_insert();  
    end = std::chrono::system_clock::now();   
   
    seconds = end - start; 
    print_data("QUICKSORT WITH INSERT SORT Time: ",seconds.count());
    time.at(6).push_back(seconds.count()); 

    start = std::chrono::system_clock::now();    
    sort.quicksort_3way();  
    end = std::chrono::system_clock::now();   
   
    seconds = end - start; 
    print_data("QUICKSORT 3WAY SORT Time: ",seconds.count());
    time.at(7).push_back(seconds.count()); 


    queue.set_data(sizes_2.at(i));
    start = std::chrono::system_clock::now();    

    queue.sort();  
    end = std::chrono::system_clock::now();   
   
    seconds = end - start; 
    print_data("QUEUE SORT Time: ",seconds.count());
    time.at(8).push_back(seconds.count()); 

  } 

  FILE * file = fopen("sort_times.data","w");
  for(unsigned int i = 0; i < sizes.size(); i++)
  {
    fprintf(file,"%ld ",sizes.at(i));
    for(unsigned int j = 0; j < 3; j++)
      fprintf(file,"%f ", time[j][i]);
   fprintf(file,"\n"); 
  }
  fclose(file);
  
  FILE * file_2 = fopen("sort_times.data_2","w");
  for(unsigned int i = 0; i < sizes_2.size(); i++)
  {
    fprintf(file_2,"%ld ",sizes_2.at(i));
    for(unsigned int j = 3; j < SORTS; j++)
      fprintf(file_2,"%f ", time[j][i]);
   fprintf(file_2,"\n"); 
  }
  fclose(file_2);
  
  plot(); 
  return 0;
}

void plot(void)
{
  FILE * gnuplot_pipe = popen("gnuplot -persistent","w");
  fprintf(gnuplot_pipe, "set style line 5; plot");  
  for(unsigned int sort = 0; sort < 3; sort++)
  {
    fprintf(gnuplot_pipe, " 'sort_times.data' using 1:%d w linespoints  title '%s' , ",sort+2,titles[sort].c_str());
  }
  fprintf(gnuplot_pipe, "\n");  

  FILE * gnuplot_pipe_2 = popen("gnuplot -persistent","w");
  fprintf(gnuplot_pipe_2, "set style line 5; plot");  
  for(unsigned int sort = 3; sort < SORTS; sort++)
  {
    fprintf(gnuplot_pipe_2, " 'sort_times.data_2' using 1:%d w linespoints  title '%s' , ",sort-1,titles[sort].c_str());
  }
  fprintf(gnuplot_pipe_2, "\n");  


}

void print_data(std::string s, double val )
{
  std::cout<<std::left<<std::setw(33)<<s<<std::setw(5)<<std::right<< val <<std::endl;
}
