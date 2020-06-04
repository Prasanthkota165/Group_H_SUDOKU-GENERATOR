/**
 * @file Rearrange_Cols_Rows.c
 *
 * Purpose   : This function is used to generate different combinations of the sudoku,
 *	       by randomly interchanging rows,columns of the Sudoku Template.
 *
 * Language  : C
 * 
 * Author    : Prasanth Kota - prasanthkota@cmail.carleton.ca 
 *
 * Date      : 31 May, 2020.
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "../include/sudoku.h"

/**
 * @brief This function is used to generate the randomly rearranged sudoku.
 * 
 * @param[in] sudoku_template[][9] --- This parameter takes the template generating 
 * 				       in the function generate_sudoku_template.c
 * @param[in] rearranged_sudoku[][9] --- This parameter is the updated randomized 
 * 					 sudoku template.
 */
void rearrange_cols_rows(int sudoku_template[][9], int rearranged_sudoku[][9]){
  int i,j;
  int a[9][9]; 
  int b_1[9][3];
  int b_2[9][3];
  int b_3[9][3];
  int c_1[3][9];
  int c_2[3][9];
  int c_3[3][9];
  for (i=0;i<9;i++){
 	for (j=0;j<9;j++){ /* copy the sudoku_template into a */
		a[i][j] = sudoku_template[i][j];
	}
  }
  swap(a); /* swapping the values in the sudoku_template */
  change_columns(a,0,1,2); /* Interchanging the Columns */
  change_columns(a,3,4,5);
  change_columns(a,6,7,8);
  change_rows(a,0,1,2); /* Interchanging the rows */
  change_rows(a,3,4,5);
  change_rows(a,6,7,8);
  col_groups(a,b_1,b_2,b_3); /* Interchanging the columnn groups (9x3) */
  row_groups(a,c_1,c_2,c_3); /* Interchanging the row groups (3x9) */
  for (i=0;i<9;i++){
 	for (j=0;j<9;j++){ /* copy the a template into rearranged_sudoku */
		rearranged_sudoku[i][j] = a[i][j];
	}
  }

}

/**
 * @brief This function is used to generate random numbers between [1,9] 
 *
 * @param[in] rangeLow --- This parameter determines the lowest number in the range.
 * @param[in] rangeHigh --- This parameter determines the highest number in the range.
 * @return This function returns a number between [1,9]
 */ 
int choose_number(int rangeLow, int rangeHigh) {

  int i;
  int count=1;
  int num;
  for (i = 0; i < count; i++) { 
        num = (rand() % (rangeHigh - rangeLow + 1)) + rangeLow;  
    } 
  return num;
}

/**
 * @brief This function is used to select different numbers in the 
 *        sudoku template and swap them accordingly.
 *
 * @param[in] table[][9] --- This parameter updates the sudoku template 
 *			     after successful swapping of the values.
 */ 
void swap(int table[][9]){
 
  int interchange_1; /* Defines 3 numbers to swap between them. */
  int interchange_2;
  int interchange_3;	
  srand(time(0));	
  interchange_1= choose_number(1,9);
  interchange_2= choose_number(1,9);
  interchange_3= choose_number(1,9);
  while(1){
	/* This condition is to make sure all the 3 numbers are different */
	
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
 	break;	/* If the 3 numbers are not different,then generate 3 random numbers again */
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
 * @brief This function is to change the randomly rearrange columns:
 *		1, 2 and 3 within themselves;
 *		4, 5 and 6 within themselves; and
 *		7, 8 and 9 within themselves. 
 *
 * @param[in] col_matrix[][9] --- This parameter updates the sudoku template after the 
 *				  rearrangement of the columns combinations consecutively.
 * @param[in] p --- This parameter is used to take the values of the column number.
 * @param[in] q --- This paramter is used to take the values of the 
 *		    consecutive column number after the pth column.
 * @param[in] r --- This parameter is used to take the values of the 
 *		    consecutive column number after the qth column.
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
 * @brief This function is to change the randomly rearrange rows:
 *		1, 2 and 3 within themselves;
 *		4, 5 and 6 within themselves; and
 *		7, 8 and 9 within themselves.
 *
 * @param[in] row_matrix[][9] --- This parameter updates the sudoku template 
 *				  after the rearrangement of the rows combination consecutively.
 * @param[in] x --- This parameter is used to take the values of the row number.
 * @param[in] y --- This paramter is used to take the values of the 
 *		    consecutive row number after the xth row.
 * @param[in] z --- This parameter is used to take the values of the
 *		    consecutive row number after the yth row. 
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

/**
 * @brief This function is used to randomly rearrange the sudoku template
 *         in 3 column groups of size 9x3.
 *
 * @param[in] column_group[][9] --- This parameter updates the sudoku template
 *				    after the rearrangement of 3 column groups (9x3 size).
 * @param[in] b_1[9][3] --- This parameter is used to copy the first 9x3 size 
 *			    of sudoku template and overwrite it's values.
 * @param[in] b_2[9][3] --- This parameter is used to copy the second 9x3 size 
 *		            of sudoku template and overwrite it's values.
 * @param[in] b_3[9][3] --- This parameter is used to copy the third 9x3 size
 *			    of sudoku template and overwrite it's values.
 */
void col_groups(int column_group[][9], int b_1[9][3], int b_2[9][3], int b_3[9][3]){
  int i,j;
  int k,l;
  for(i=0;i<9;i++){
	for(j=0;j<3;j++){ /* copy into the column groups (b_1,b_2,b_3)(9x3) */
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
	for(j=0;j<3;j++){ /* copy into the column_group(9x9) to interchange column group(9x3) */
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

/** 
 * @brief This function is used to randomly rearrange the sudoku template 
 *        in 3 row groups of size 3x9.
 *
 * @param[in] r_group[][9] --- This parameter updates the sudoku template 
 *			       after the rearrangement of 3 row groups (3x9 size).
 * @param[in] c_1[3][9] --- This parameter is used to copy the first 3x9 size 
 *			    of sudoku template and overwrite it's values.
 * @param[in] c_1[3][9] --- This parameter is used to copy the second 3x9 size
 *		            of sudoku template and overwrite it's values.
 * @param[in] c_1[3][9] --- This parameter is used to copy the third 3x9 size
 *			    of sudoku template and overwrite it's values.
 */
void row_groups(int r_group[][9], int c_1[3][9], int c_2[3][9], int c_3[3][9]){
  int i,j;
  int k,l;
  for(i=0;i<9;i++){
	for(j=0;j<3;j++){ /* copy into the column groups(c_1,c_2,c_3)(3x9) */
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
	for(j=0;j<3;j++){ /* copy into the r_group(9x9) to interchange row group(3x9) */
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
