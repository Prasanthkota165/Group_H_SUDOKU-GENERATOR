/**
 * @file test_rearrange_cols_rows.c
 *
 * Purpose   : This function is used to test the rearrange_cols_rows.c function
 *
 * Language  : C
 * 
 * Author    : Prasanth Kota - prasanthkota@cmail.carleton.ca 
 *
 * Date      : 19 June, 2020.
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<errno.h>
#include "../include/rearrange_rows_cols_test.h"
#include "../../include/sudoku.h"

int main(void){
    int sudoku[9][9]; /* Refers to the input parameter for the rearrange_cols_rows function */
    int rearranged_sudoku[9][9]; /* Refers to the output parameter for the rearrange_cols_rows function */
    char* log_location = "../log/rearrange_rows_cols.log"; /*Define the path*/
    FILE *log = fopen(log_location, "w"); /*Write access to the log file */
    
    fprintf(log,"REARRANGE SUDOKU ROWS, COLUMNS TESTING RESULT\n"
		"-----------------------------------------------\n");
    srand(time(0));

    if(swap_values(sudoku)){ /* Testing for 4 randomly swapped numbers in the input parameter*/
    	fputs("1. All the 4 numbers in each row are swapped randomly in the input parameter sudoku_template.\n"
	      "rearrange_cols_rows function has ****PASSED**** the swapping test.\n",log);
    } else {
    	fputs("1. Two or More numbers in a row are identical in the sudoku_template.\n"
	      "rearrange_cols_rows function has ***FAILED*** the swapping test.\n",log);
    }
    fputs("-----------------------------------------------\n",log);

    if(beyond_boundary_1(sudoku)){ /* Testing the input parameter for 9x9 boundary */
    	fputs("2. Input parameter of the function is beyond the 9X9 boundaries.\n"
	"rearrange_cols_rows function has ***FAILED*** the input boundary test.\n",log);
    }else {
 	fputs("2. Input parameter of the function is within the 9X9 boundaries.\n"
	"rearrange_cols_rows function has ***PASSED*** the input boundary test.\n",log);
    }
    fputs("-----------------------------------------------\n",log);

    if( beyond_boundary_2(rearranged_sudoku)){/* Testing the output parameter for 9x9 boundary */
    	fputs("3. output parameter of the function is beyond the 9X9 boundaries.\n"
	"rearrange_cols_rows function has ***FAILED** the output boundary test.\n",log);
    }else {
 	fputs("3. Input parameter of the function is within the 9X9 boundaries.\n"
	"rearrange_cols_rows function has ***PASSED*** the output boundary test.\n",log);
    }
    fputs("-----------------------------------------------\n",log);

    if(beyond_range_1(sudoku)){ /*Testing for values range in the input parameter */
	fputs("4. The input parameter sudoku_template has the values out of range [1,9] in any row,column,3x3 block \n"
	"rearrange_cols_rows function input has ***FAILED*** the range test.\n",log);
    	
    } else {
	fputs("4. The input parameter sudoku_template has the values in the range [1,9] in rows,columns,3x3 block. \n"
	"rearrange_cols_rows function input has ***PASSED*** the range test.\n",log);
	
    }
    fputs("-----------------------------------------------\n",log);

    if(beyond_range_2(rearranged_sudoku)){ /*Testing for values range in the output parameter */
	fputs("5. The input parameter sudoku_template has the values out of range [1,9] in any row,column,3x3 block. \n"
	"rearrange_cols_rows function has ***FAILED*** the range test.\n",log);
    } else {
	fputs("5. The output parameter sudoku_template has the values in the range [1,9] in rows,columns,3x3 block. \n"
	"rearrange_cols_rows function output has ***PASSED*** the range test.\n",log);
    }
    fputs("-----------------------------------------------\n",log);

    if(identical_sudokus(sudoku, rearranged_sudoku)){ /* Testing for identical i/p and o/p parameters */
    	fputs("6. Input and output parameters of the function are identical.\n" 
	"rearrange_rols_cols function has ***FAILED***  the identical test.\n",log);
    }  else {
	fputs("6. Input and output parameters of the function are not identical.\n"
	"rearrange_cols_rows function has ***PASSED*** the identical test.\n",log);
    }
    fputs("-----------------------------------------------\n",log);
    fclose(log);
    return 0;
}
 
/* This function is to check whether the rearrange_rows_cols is actually 
 * swapping randomly selected numbers in the input parameter.
 */ 
_Bool swap_values(int sudoku[][9]){
    generate_sudoku_template(sudoku); /* load the i/p parameter */
    int i,j;
    int a[9][9];
    int check=0;
    int sum=0;
    _Bool flag;
    char* log_location = "../log/rearrange_rows_cols.log"; /*Define the path*/
    FILE *log = fopen(log_location, "a"); /*Appends access to the log file */
    fputs("->Reference to Test 1 \n------------\n",log);
    fputs("  Input parameter sudoku_template: \n",log);
    for(i=0;i<9;i++){
	for(j=0;j<9;j++){ /* copy the values of sudoku to a */
		a[i][j] = sudoku[i][j];
		fprintf(log,"  %d ", sudoku[i][j]);
	}
	fprintf(log,"\n");
    }
    fputs("  Output paramter rearranged_sudoku: \n",log);
    swap(a); /* do the swapping of 4 numbers in a */
    for(i=0;i<9;i++){
	for(j=0;j<9;j++){
		if(sudoku[i][j]!=a[i][j]){ /* check how many numbers in the row are swapped */ 
			check++;		
		}
		fprintf(log,"  %d ", a[i][j]);
	}
	fprintf(log,"-- 4 numbers swapped \n");
	sum=sum+check;
	check=0;
    }
    fputs("--------------------------\n",log);
    if(sum==36){ /* mathematically,9 rows with 4 numbers swapped should contain 36 numbers swapped */
    	return true;
    } else {
	return false;	
	}
}

/*This function is to check whether the input parameter is within the 9x9 boundaries*/
_Bool beyond_boundary_1(int sudoku[][9]){
   
    int i,j;
    int check_1=0,check_2=0;
    int l,k;
    int a[9][9];
    char* log_location = "../log/rearrange_rows_cols.log"; /*Define the path*/
    FILE *log = fopen(log_location, "a"); /*Append access to the log file */
    fputs("->Reference to Test 2, within 9x9 boundary \n------------\n",log);
    for(i=0;i<9;i++){
	for(j=0;j<9;j++){ /* copy the sudoku to a*/
		a[i][j] = sudoku[i][j];
	}
    }
    generate_sudoku_template(a); 
    l=sizeof(a)/sizeof(a[0]); /* no. of rows after loading a*/
    k=sizeof(a[0])/sizeof(a[0][0]); /* no. of columns after loading a*/
    for(i=0;i<l;i++){
    	for(j=0;j<k;j++){ /* check rows whether it has any elements beyond the boundaries */
		if((a[i][j]>9) || (a[i][j]<1)){
			check_1++;		
		}
	}
    }
    for(i=0;i<l;i++){ /* check columns whether it has any elements beyond the boundaries */
    	for(j=0;j<k;j++){
		if((a[j][i]>9) || (a[j][i]<1)){
			check_2++;		
		}
	}
    } 
    fprintf(log,"The row boundary of the input parameter sudoku_template is: %d\n",l);
    fprintf(log,"The column boundary of the input parameter sudoku_template is: %d\n",k);
     fputs("--------------------------\n",log);
    /* if nothing, then tests are passed*/ 
    if((check_1!=0) || (check_2!=0)){
     return true;
    } else {
	return false;	
    }
}

/*This function is to check whether the output parameter is within the 9x9 boundaries*/
_Bool beyond_boundary_2(int rearranged_sudoku[][9]){
    int c[9][9];
    int i,j;
    int check_3=0,check_4=0;
    int l,k;
    int b[9][9];
    char* log_location = "../log/rearrange_rows_cols.log"; /*Define the path*/
    FILE *log = fopen(log_location, "a"); /*Append access to the log file */
    fputs("->Reference to Test 3, Within 9X9 boundary \n------------\n",log);
    for(i=0;i<9;i++){
	for(j=0;j<9;j++){ /* copy the garabage values to b */
		b[i][j]=rearranged_sudoku[i][j];	
	}
    }
    generate_sudoku_template(c); /* load c like the i/p parameter */
    rearrange_cols_rows(c,b); /* rearrange b with c */
    l=sizeof(b)/sizeof(b[0]);  /* no. of rows after loading b*/
    k=sizeof(b[0])/sizeof(b[0][0]); /* no. of columns after loading b*/
    for(i=0;i<l;i++){/* check rows whether it has any elements beyond the boundaries */
    	for(j=0;j<k;j++){
		if((b[i][j]>9) || (b[i][j]<1)){
			check_3++;		
		}
	}
    }
    for(i=0;i<l;i++){/* check columns whether it has any elements beyond the boundaries */
    	for(j=0;j<k;j++){
		if((b[j][i]>9) || (b[j][i]<1)){
			check_4++;		
		}
	}
    }
    fprintf(log,"The row boundary of the input parameter rearranged_sudoku is: %d\n",l);
    fprintf(log,"The column boundary of the input parameter rearranged_sudoku is: %d\n",k);
    fputs("--------------------------\n",log);
    /* if nothing, then tests are passed*/ 
    if((check_3!=0) || (check_4!=0)){
     return true;
    } else {
	return false;	
    }
}

/* This function is to check the values of the i/p parameter should not
 * be beyond the range [1,9]
 */ 
_Bool beyond_range_1(int sudoku[][9]){
    int i,j;
    int k=0,l=2,x=0,y=2;
    int check_1=0,check_2=0,check_3=0;
    char* log_location = "../log/rearrange_rows_cols.log"; /*Define the path*/
    FILE *log = fopen(log_location, "a"); /*Append access to the log file */
    fputs("->Reference to Test 4 \n------------\n",log);
    fputs("  Check the values of sudoku_template in the range [1,9]\n\n",log);
    for(i=0;i<9;i++){ /* checking rows for in [1,9] */
	for(j=0;j<9;j++){
		if((sudoku[i][j] <=9) && (sudoku[i][j]>=1)){
			check_1++;			
		} else {
			check_1--;		
		}
		fprintf(log,"  %d ",sudoku[i][j]);
	}
	fprintf(log,"\n");
    }
    for(i=0;i<9;i++){ /* checking columns for in [1,9] */
	for(j=0;j<9;j++){
		if((sudoku[j][i] <=9) && (sudoku[j][i]>=1)){
			check_2++;			
		} else {
			check_2--;		
		}
	}
    }
    while(x<=8) { /* checking 3x3 for in [1,9] */
        while(k<=8) {
            for (int i=x;i<=y;i++) {
                for(int j=k;j<=l;j++) {
			if((sudoku[i][j] <=9) && (sudoku[i][j]>=1)){
				check_3++;			
			} else {
				check_3--;		
			}
                }
            }
	    k=k+3;
            l=l+3;
	}
   	k=0;
        l=2;
        x=x+3;
        y=y+3;
    }
     fputs("--------------------------\n",log);
    /* mathematically, if everything is in [1,9], all should be 81 */
    if((check_1==81) && (check_2==81) && (check_3==81)){
        return false;
    } else {
	return true;
    }    
}

/* This function is to check the values of the o/p parameter should not
 * be beyond the range [1,9]
 */ 
_Bool beyond_range_2(int rearranged_sudoku[][9]){
    int b[9][9];
    generate_sudoku_template(b);
    rearrange_cols_rows(b,rearranged_sudoku);
    int i,j;
    int k=0,l=2,x=0,y=2;
    int check_4=0,check_5=0,check_6=0;
    char* log_location = "../log/rearrange_rows_cols.log"; /*Define the path*/
    FILE *log = fopen(log_location, "a"); /*Append access to the log file */
    fputs("->Reference to Test 5 \n------------\n",log);
    fputs("  Check the values of rearranged_sudoku in the range [1,9]\n\n",log);
    for(i=0;i<9;i++){
	for(j=0;j<9;j++){  /* checking rows for in [1,9] */
		if((rearranged_sudoku[i][j] <=9) &&
			 (rearranged_sudoku[i][j]>=1)){
			check_4++;			
		} else {
			check_4--;		
		}
		fprintf(log,"  %d ",rearranged_sudoku[i][j]);
	}
	fprintf(log,"\n");
    }
    for(i=0;i<9;i++){
	for(j=0;j<9;j++){/* checking columns for in [1,9] */
		if((rearranged_sudoku[j][i] <=9) && 
			(rearranged_sudoku[j][i]>=1)){
			check_5++;			
		} else {
			check_5--;		
		}
	}
    }
    while(x<=8) {
        while(k<=8) {
            for (int i=x;i<=y;i++) { /* checking 3x3 for in [1,9] */
                for(int j=k;j<=l;j++) {
			if((rearranged_sudoku[i][j] <=9) &&
				 (rearranged_sudoku[i][j]>=1)){
				check_6++;			
			} else {
				check_6--;		
			}
                }
            }
	    k=k+3;
            l=l+3;
	}
   	k=0;
        l=2;
        x=x+3;
        y=y+3;
    }
    fputs("--------------------------\n",log); 
    /* mathematically, if everything is in [1,9], all should be 81 */
    if((check_4==81) && (check_5==81) && (check_6==81)){
        return false;
    } else {
	return true;
    }    
}

/* This function is to check the i/p and o/p parameters are identical or not */
_Bool identical_sudokus(int sudoku[][9], int rearranged_sudoku[][9]){
    generate_sudoku_template(sudoku);
    char* log_location = "../log/rearrange_rows_cols.log"; /*Define the path*/
    FILE *log = fopen(log_location, "a"); /*Append access to the log file */
    fputs("->Reference to Test 6, Identical sudokus\n------------\n",log);
    int i,j,check=0;
    fputs("  Input parameter rearranged_sudoku: \n",log);
    for(i=0;i<9;i++){ /* checking for same numbers */
	for(j=0;j<9;j++){
		fprintf(log,"  %d ", sudoku[i][j]);	
	}
	fprintf(log,"\n");
    }
    fputs("\n  Output parameter rearranged_sudoku: \n",log);
    for(i=0;i<9;i++){ /* checking for same numbers */
	for(j=0;j<9;j++){
		if(sudoku[i][j] == rearranged_sudoku[i][j]){
			check++;		
		}
		fprintf(log,"  %d ", rearranged_sudoku[i][j]);	
	}
	fprintf(log,"\n");
    }
    fputs("\n  Check the numbers with the input parameter.\n--------------------------\n",log); 
    if(check == 81){ /*if all numbers are equal, then identical */
	return true;
    } else {
	return false;
	}
}

