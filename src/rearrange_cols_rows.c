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
#include "../include/sudoku.h"

/** 
 * This function will rearrange the sudoku template and produce different
 * combinations of it.
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
  change_columns(a,0,1,2); /* Interchanging the columns */
  change_columns(a,3,4,5);
  change_columns(a,6,7,8);
  change_rows(a,0,1,2); /* Interchanging the rows */
  change_rows(a,3,4,5);
  change_rows(a,6,7,8);
  col_groups(a,b_1,b_2,b_3); /* Interchanging the column groups(9x3) */
  row_groups(a,c_1,c_2,c_3); /* Interchanging the row groups(3x9) */
  for (i=0;i<9;i++){
 	for (j=0;j<9;j++){ /* copy the a[][9] template into rearranged_sudoku */
		rearranged_sudoku[i][j] = a[i][j];
	}
  }

}

/**
 * Randomly choose a number between 1 and 9.  
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
 * Three different numbers will be randomly selected from each row and swap between them.
 */ 
void swap(int table[][9]){
 
  int interchange_1; /* Defines 3 numbers to swap between them. */
  int interchange_2;
  int interchange_3;
  int interchange_4;	
 	
  interchange_1= choose_number(1,9);
  interchange_2= choose_number(1,9);
  interchange_3= choose_number(1,9);
  interchange_4= choose_number(1,9);
  while(1){
	/* This condition is to make sure all the 3 numbers are different */
	
  	if((interchange_1 != interchange_2) && \
	  (interchange_1 != interchange_3) && \
	  (interchange_1 != interchange_4) && \
	  (interchange_2 != interchange_3)&& \
	  (interchange_2 != interchange_4)&& \
	  (interchange_3 != interchange_4)){
  	  int i,j;
  		for(i=0;i<9;i++){
  			for(j=0;j<9;j++){
				if (table[i][j]==interchange_1){
					table[i][j]=interchange_4;
		
				} else if (table[i][j]==interchange_2){

					table[i][j]=interchange_1;
			
				} else if (table[i][j]==interchange_3){
					
					table[i][j] = interchange_2;
				}
				else if (table[i][j]==interchange_4){
					
					table[i][j] = interchange_3;
				}
				
 			}
  		}
 	break;	/* If the 3 numbers are not different,then generate 3 random numbers again */
	} else if((interchange_1 == interchange_2) || \
		  (interchange_1 == interchange_3) || \
		  (interchange_1 == interchange_4) || \
		  (interchange_2 == interchange_3) || \
		  (interchange_2 == interchange_4)|| \
		  (interchange_4 == interchange_3)){
		interchange_1= choose_number(1,9);
  		interchange_2= choose_number(1,9);
		interchange_3= choose_number(1,9);	
		interchange_4= choose_number(1,9);
	}
  }
}

/**
 * Randomly interchange the columns:
 *		1, 2 and 3 within themselves;
 *		4, 5 and 6 within themselves; and
 *		7, 8 and 9 within themselves. 
 */
void change_columns(int col_matrix[][9], int p, int q, int r){
  int i,count_1,count_2,count_3;;
  int num_1,num_2,num_3; /*choose the rows to get swapped with random generator*/
  num_1= choose_number(p,r);
  num_2= choose_number(p,r);
  num_3= choose_number(p,r);
  while(1){
  	if((num_1!=num_2) && (num_2!=num_3) && (num_3!=num_1)){
  		for(i=0;i<9;i++){
			count_1= col_matrix[i][num_1];
			count_2= col_matrix[i][num_2];
			count_3= col_matrix[i][num_3];
			col_matrix[i][p]=count_1;
			col_matrix[i][q]=count_2;
			col_matrix[i][r]=count_3;					
  		}
  	break;
  	} else if((num_1==num_2) || (num_2==num_3) || (num_3==num_1)){
  		  num_1= choose_number(p,r);
  		  num_2= choose_number(p,r);
    		  num_3= choose_number(p,r);
	}
  }

}

/**
 * Randolmy interchange the rows:
 *		1, 2 and 3 within themselves;
 *		4, 5 and 6 within themselves; and
 *		7, 8 and 9 within themselves.
 */
void change_rows(int row_matrix[][9], int x, int y, int z){
  int i, count_1,count_2,count_3;
  int ele_1,ele_2,ele_3;
  ele_1= choose_number(x,z);
  ele_2= choose_number(x,z);
  ele_3= choose_number(x,z);
  while(1){
  	if((ele_1!=ele_2) && (ele_2!=ele_3) && (ele_3!=ele_1)){
  		for(i=0;i<9;i++){
  			count_1= row_matrix[ele_1][i];
			count_2= row_matrix[ele_2][i];
			count_3= row_matrix[ele_3][i];
			row_matrix[x][i]=count_1;
			row_matrix[y][i]=count_2;
			row_matrix[z][i]=count_3;
  		}
	break;
	} else if((ele_1==ele_2) || (ele_2==ele_3) || (ele_3==ele_1)){
  		  ele_1= choose_number(x,z);
  		  ele_2= choose_number(x,z);
    		  ele_3= choose_number(x,z);
	}
}
}
/**
 * Swapping between the 3 column groups of size 9x3 of the sudoku template.
 */
void col_groups(int column_group[][9], int b_1[9][3], int b_2[9][3], int b_3[9][3]){
  int i,j;
  int k,l;
  int ch_1,ch_2,ch_3; /*choose the column groups to swap randomly*/
  int order;
  ch_1=choose_number(1,3);
  ch_2=choose_number(1,3);
  ch_3=choose_number(1,3);
  
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

  while(1){
 	if((ch_1!=ch_2) && (ch_2!=ch_3) && (ch_3!=ch_1)){
  		for(i=0;i<9;i++){
			order = ch_1;
			for(j=0;j<3;j++){
				if (order == 1){
 					column_group[i][j]=b_1[i][j];
				} else if (order == 2){
					column_group[i][j]=b_2[i][j];
				} else if (order == 3){
					column_group[i][j]=b_3[i][j];
				}
			}  
			k=0;
			order = ch_2;
			for(j=3;j<6;j++){
 				if (order == 1){
 					column_group[i][j]=b_1[i][k] ;
				} else if (order == 2){
					column_group[i][j]=b_2[i][k] ;
				} else if (order == 3){
					column_group[i][j]=b_3[i][k] ;
				}
				k++;
			} 
			l=0;
			order = ch_3;

			for(j=6;j<9;j++){
 				if (order == 1){
 					column_group[i][j]=b_1[i][l];
				} else if (order == 2){
					column_group[i][j]=b_2[i][l];
				} else if (order == 3){
					column_group[i][j]=b_3[i][l];
				}
				l++;
			} 
  		} 
	break;
	} else if((ch_1==ch_2) || (ch_2==ch_3) || (ch_3==ch_1)){
  		  ch_1= choose_number(1,3);
  		  ch_2= choose_number(1,3);
    		  ch_3= choose_number(1,3);
	}
  }

}

/**
 * Swapping between the 3 row groups of size 3x9 of the sudoku template.
 */
void row_groups(int r_group[][9], int c_1[3][9], int c_2[3][9], int c_3[3][9]){
  int i,j;
  int k,l;
  int rw_1,rw_2,rw_3; /*choose the row groups to swap randomly*/
  int order;
  rw_1=choose_number(1,3);
  rw_2=choose_number(1,3);
  rw_3=choose_number(1,3);

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
 
  while(1){
 	if((rw_1!=rw_2) && (rw_2!=rw_3) && (rw_3!=rw_1)){
  		for(i=0;i<9;i++){
			order = rw_1;
			for(j=0;j<3;j++){ /* copy into the column_group(9x9) to interchange column group(9x3) */
				if (order == 1){
 					r_group[j][i]=c_1[j][i];
				} else if (order == 2){
					r_group[j][i]=c_2[j][i];
				} else if (order == 3){
					r_group[j][i]=c_3[j][i];
				}
			}  

			k=0;
			order = rw_2;
			for(j=3;j<6;j++){
 				if (order == 1){
 					r_group[j][i]=c_1[k][i];
				} else if (order == 2){
					r_group[j][i]=c_2[k][i];
				} else if (order == 3){
					r_group[j][i]=c_3[k][i];
				}
				k++;
			} 
			l=0;
			order = rw_3;
			for(j=6;j<9;j++){
 				if (order == 1){
 					r_group[j][i]=c_1[l][i];
				} else if (order == 2){
					r_group[j][i]=c_2[l][i];
				} else if (order == 3){
					r_group[j][i]=c_3[l][i];
				}
				l++;
			} 
  		} 
	break;
	} else if((rw_1==rw_2) || (rw_2==rw_3) || (rw_3==rw_1)){
  		  rw_1= choose_number(1,3);
  		  rw_2= choose_number(1,3);
    		  rw_3= choose_number(1,3);
	}
  }

}
