/*
* TITLE      : generate_sudoku_template_test.c 
*
* Purpose   : Tests the function generate_sudoku_template.c
*
* Language  : C
*
* Author    : Rishith Rao, 
* GitHub ID : rishithrao57 
* Date      : 21 June 2020
*
**/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include "../../include/sudoku.h"

int main() {
    char* log_location = "../log/generate_sudoku_template.log"; /*Define the path*/
    FILE *log = fopen(log_location, "w"); /*Write access to the log file */
    srand(time(0));
    int sudoku_temp[9][9]={0};
    int count=0;
    _Bool b;
    generate_sudoku_template(sudoku_temp);
    int i,j;
    fprintf(log,".........The function will return this matrix..........\n\n");
    for(i=0;i<9;i++){
        fprintf(log,"   ");
	    for(j=0;j<9;j++){
	        fprintf(log,"%d ",sudoku_temp[i][j]);
        }
        fprintf(log,"\n");
    }

    for(i=0;i<9;i++){
       	for(j=0;j<9;j++){
	        if(sudoku_temp[i][j]==0){
                count++;
            }
        }
    }
    
    if(count == 0 ){
        fputs("\n\nThe function successfully generated and returned the 9X9 matrix",log);
    } else { 
        fputs("Function failed to generated and returned the 9X9 matrix",log); 
    }
    fclose(log);
    return 0;
}
