#include<stdlib.h>
#include<time.h>
#include<stdio.h>


void fill_table(int * table, int N);
void generate_and_fill_tables(int ** table,int * sizes,int number_of_tables);
void free_tables(int **table, int N);

void gnuplot_save_table_data(int *table, int N,int i);
void gnuplot_plot_table_data(int *table, int N);
void gnuplot_create_animation(char * directory, int N);


