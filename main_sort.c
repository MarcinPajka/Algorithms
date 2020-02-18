#include "sort.h"
#include "misc.h"

int main(void)
{ 
  int table_1[10];
  int table_2[100];
  int table_3[1000];
  int table_4[2500];
  int table_5[5000];
  int table_6[10000];  
 
 fill_table(table_1,10);  
  fill_table(table_2,100);  
  fill_table(table_3,1000);  
  fill_table(table_4,2500);  
  fill_table(table_5,5000);  
  fill_table(table_6,10000);
  
  long int timer = clock();
 
  selection(table_1,10);
  printf("Selection sort size 10 cycles:  %ld \n",clock() - timer );
  timer = clock(); 
  selection(table_2,100);
  printf("Selection sort size: 100 cycles:  %ld \n",clock() - timer );
  timer = clock(); 
  selection(table_3,1000);
  printf("Selection sort size: 1000 cycles:  %ld \n",clock() - timer );
  timer = clock(); 
  selection(table_4,2500);
  printf("Selection sort size: 2500 cycles:  %ld \n",clock() - timer );
  timer = clock(); 
  selection(table_5,5000);
  printf("Selection sort size: 5000 cycles:  %ld \n",clock() - timer ); 
  timer = clock(); 
  selection(table_6,10000);
  printf("Selection sort size 10000 cycles %ld \n",clock() - timer ); 

  return 0;
}
