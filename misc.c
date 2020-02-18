#include "misc.h"

void fill_table(int * table, int N)
{
  srand(time(0));
  
  for(int i = 0; i < N; i++)
  {
    table[i] = rand() % 501;
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

void gnuplot_save_table_data(int *table, int N, int i)
{
  FILE * gnuplot_pipe = popen("gnuplot ","w");
  fprintf(gnuplot_pipe, "set terminal png size 400,300; set output 'tmp_charts/file_%d.png' ;plot '-' w boxes \n",i);
  for(int i = 0; i < N; i++)
  {
    fprintf(gnuplot_pipe,"%d %d\n",i , table[i]);
  }
  fprintf(gnuplot_pipe, "e\n");
}
void gnuplot_plot_table_data(int *table, int N)
{
  FILE * gnuplot_pipe = popen("gnuplot -persistent","w");
  fprintf(gnuplot_pipe, "plot '-' w boxes \n");
  for(int i = 0; i < N; i++)
  {
    fprintf(gnuplot_pipe,"%d %d\n",i , table[i]);
  }
  fprintf(gnuplot_pipe, "e\n");
}

void gnuplot_create_animation(char * directory, int N)
{
  FILE * gnuplot_pipe = popen("gnuplot -persistent","w");
  fprintf(gnuplot_pipe, "splot style data lines\n");
  fprintf(gnuplot_pipe, "do for [i=0:%d]{plot sprintf('tmp_charts/file_%d.png');pause 0.5 } \n",N,N);
  fprintf(gnuplot_pipe, "e\n");
}

