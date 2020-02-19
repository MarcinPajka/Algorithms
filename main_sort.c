#include "sort.h"
#include "misc.h"

int main(void)
{ 
  int N = 23; 
  int * table[N];
  int sizes[] =   {128,500,1000,1500,2000,2500,3000,3500,4000,4500,5000,6000,7000,8000,9000,10000,11000,12000,13000,14000,15000,16000};
  //int sizes[] =   {128,500,1000,1500,2000,2500,3000,3500,4000,5000,10000,20000,30000,40000,50000,100000,200000,300000};
  generate_and_fill_tables(table,sizes,N);
 
  int number_of_sorts = 4;
 // char * sort_types[] = {"Selection","Insertion","Shell","Merge","Merge_BU"};
 char * sort_types[] = {"Merge","Merge_BU","Quick","Quick_3way"};


  int * times[number_of_sorts];

  for(int i = 0; i < number_of_sorts; i++)
    times[i] = (int *)malloc( sizeof(int) * N );
 
  for(int sort_type = 0; sort_type < number_of_sorts; sort_type++)
  {
    for(int i = 0 ; i < N ; i++)
    { 
      times[sort_type][i] = sort(table[i],sizes[i],sort_types[sort_type]);
      printf(" %s sort, data size: %-7d cycles:  %d \n",sort_types[sort_type],sizes[i], times[sort_type][i]);
    }
    free_tables(table, N); 
    generate_and_fill_tables(table,sizes,N);
  }

  gnuplot_save_table_data(times,sizes,N, number_of_sorts);
  gnuplot_plot_table_data(number_of_sorts, sort_types);

  free_tables(table, N);
  free_tables(times,number_of_sorts);

  return 0;
}
