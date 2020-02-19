#include "misc.h"

void fill_table(int * table, int N)
{
  srand(time(0));
  
  for(int i = 0; i < N; i++)
  {
    table[i] = rand() % 10000;
  }
}

void  generate_and_fill_tables(int ** table,int * sizes,int number_of_tables)
{
  for(int i = 0; i < number_of_tables; i++)
  {
    table[i] = (int *)malloc((sizeof(int)) * sizes[i]);
    fill_table(table[i],sizes[i]);
  }  
}

void free_tables(int **table, int N)
{
  for(int i = 0; i < N; i++)
    free(table[i]);
}

void gnuplot_save_table_data(int **table,int * sizes, int N, int sorts)
{
  FILE * file = fopen("sort_times.data","w");

  for(int i = 0; i < N; i++)
  {
    fprintf(file,"%d ",sizes[i]);
    for(int j = 0; j < sorts; j++)
      fprintf(file,"%d ", table[j][i]);
   fprintf(file,"\n"); 
  }
  fclose(file);
}
void gnuplot_plot_table_data(int number_of_sorts,char ** titles)
{
  FILE * gnuplot_pipe = popen("gnuplot -persistent","w");
  fprintf(gnuplot_pipe, "set style line 5  ;plot");  
  for(int sort = 0; sort < number_of_sorts; sort++)
  {
    fprintf(gnuplot_pipe, " 'sort_times.data' using 1:%d w linespoints  title '%s' , ",sort+2,titles[sort]);
  }
  fprintf(gnuplot_pipe, "\n");  
}

void gnuplot_create_animation(char * directory, int N)
{
  FILE * gnuplot_pipe = popen("gnuplot -persistent","w");
  fprintf(gnuplot_pipe, "splot style data lines\n");
  fprintf(gnuplot_pipe, "do for [i=0:%d]{plot sprintf('tmp_charts/file_%d.png');pause 0.5 } \n",N,N);
  fprintf(gnuplot_pipe, "e\n");
}

