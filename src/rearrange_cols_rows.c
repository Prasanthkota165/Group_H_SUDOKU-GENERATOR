/**
 * @file Rearrange_Cols_Rows.c
 *
 * @brief This file is used to generate different combinations of the sudoku,
 *	   by randomly interchanging rows,columns of the Sudoku Template.
 *
 * @author Prasanth Kota - prasanthkota@cmail.carleton.ca 
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "../include/sudoku.h"

void rearrange_cols_rows(int sudoku_template[][9], int rearranged_sudoku[][9]){
  int i,j;
  int a[9][9];
  for (i=0;i<9;i++){
 	for (j=0;j<9;j++){
		a[i][j] = sudoku_template[i][j];
	}
  }
  swap(a);
  change_columns(a,0,1,2);
  change_columns(a,3,4,5);
  change_columns(a,6,7,8);
  change_rows(a,0,1,2);
  change_rows(a,3,4,5);
  change_rows(a,6,7,8);
  int b_1[9][3];
  int b_2[9][3];
  int b_3[9][3];
  int c_1[3][9];
  int c_2[3][9];
  int c_3[3][9];
  col_groups(a,b_1,b_2,b_3);
  row_groups(a,c_1,c_2,c_3);
  for (i=0;i<9;i++){
 	for (j=0;j<9;j++){
		rearranged_sudoku[i][j] = a[i][j];
	}
  }

}

  // This function is used to generate random numbers between [1,9].

int choose_number(int rangeLow, int rangeHigh) {

  int i;
  int count=1;
  int num;
  for (i = 0; i < count; i++) { 
        num = (rand() % (rangeHigh - rangeLow + 1)) + rangeLow;  
    } 
  return num;
}

  // This function will swap any 3 different numbers in the sudoku template.

void swap(int table[][9]){
 
  int interchange_1;
  int interchange_2;
  int interchange_3;	
  srand(time(0));	
  interchange_1= choose_number(1,9);
  interchange_2= choose_number(1,9);
  interchange_3= choose_number(1,9);
  while(1){
	// This condition is to make sure all the 3 numbers are different.
	
  	if((interchange_1 != interchange_2) && \
	  (interchange_2 != interchange_3) && \
	  (interchange_1 != interchange_3)){
  	  int i,j;
  		for(i=0;i<9;i++){
  			for(j=0;j<9;j++){
				if (table[i][j]==interchange_1){
					table[i][j]=interchange_2;
		
				} else if (table[i][j]==interchange_2){

					table[i][j]=interchange_3;
			
				} else if (table[i][j]==interchange_3){
					
					table[i][j] = interchange_1;
				}
				
 			}
  		}
 	break;	
	} else if((interchange_1 == interchange_2) || \
		  (interchange_2 == interchange_3) || \
		  (interchange_1 == interchange_3)){
		interchange_1= choose_number(1,9);
  		interchange_2= choose_number(1,9);
		interchange_3= choose_number(1,9);	
	}
  }
}

/**
* This function is to change the randomly rearrange columns:
		1, 2 and 3 within themselves;
		4, 5 and 6 within themselves; and
		7, 8 and 9 within themselves. 
*/

void change_columns(int col_matrix[][9], int p, int q, int r){
  int i,count;
  for(i=0;i<9;i++){
	  count = col_matrix[i][p];
	  col_matrix[i][p]=col_matrix[i][q];
  	  col_matrix[i][q]=col_matrix[i][r];
  	  col_matrix[i][r]= count;
  }

}

/**
* This function is to change the randomly rearrange rows:
		1, 2 and 3 within themselves;
		4, 5 and 6 within themselves; and
		7, 8 and 9 within themselves. 
*/

void change_rows(int row_matrix[][9], int x, int y, int z){
  int i, count;
  for(i=0;i<9;i++){
  	count = row_matrix[x][i];
  	row_matrix[x][i]=row_matrix[y][i];
  	row_matrix[y][i]=row_matrix[z][i];
  	row_matrix[z][i]=count;
  }

}

  /* This function is used to randomly rearrange the sudoku template
     in 3 column groups of size 9x3. */

void col_groups(int column_group[][9], int b_1[9][3], int b_2[9][3], int b_3[9][3]){
  int i,j;
  int k,l;
  for(i=0;i<9;i++){
	for(j=0;j<3;j++){
 		b_1[i][j]=column_group[i][j];
	}  
 	k=0;
	l=0;
	for(j=3;j<6;j++){
 		b_2[i][k]=column_group[i][j];
		k=k+1;
	} 
	for(j=6;j<9;j++){
 		b_3[i][l]=column_group[i][j];
		l++;
	} 
  } 

  for(i=0;i<9;i++){
	for(j=0;j<3;j++){
 		column_group[i][j]=b_2[i][j] ;
	}  
	k=0;
	for(j=3;j<6;j++){
 		column_group[i][j]=b_3[i][k];
		k++;
	} 
	l=0;
	for(j=6;j<9;j++){
 		column_group[i][j]=b_1[i][l];
		l++;
	} 
  } 

}

  /* This function is used to randomly rearrange the sudoku template 
     in 3 row groups of size 3x9.*/

void row_groups(int r_group[][9], int c_1[3][9], int c_2[3][9], int c_3[3][9]){
  int i,j;
  int k,l;
  for(i=0;i<9;i++){
	for(j=0;j<3;j++){
 		c_1[j][i]=r_group[j][i];
	}  
	k=0;
	for(j=3;j<6;j++){
 		c_2[k][i]=r_group[j][i];
		k++;
	} 
	l=0;
	for(j=6;j<9;j++){
 		c_3[l][i]=r_group[j][i];
		l++;
	} 
  } 
 
  for(i=0;i<9;i++){
	for(j=0;j<3;j++){
 		r_group[j][i]=c_2[j][i] ;
	}  
	k=0;
	for(j=3;j<6;j++){
 		r_group[j][i]=c_3[k][i];
		k++;
	} 
	l=0;
	for(j=6;j<9;j++){
 		r_group[j][i]=c_1[l][i];
		l++;
	} 


  } 

}
