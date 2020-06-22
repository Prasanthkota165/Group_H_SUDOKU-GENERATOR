#include <stdio.h>
#include "../../include/sudoku.h"
//#include "../../src/generate_sudoku_template.c"

/*
* TITLE      : generate_sudoku_template_test.c 
*
* Purpose   : Generates a pre-defined sudoku templete
*
* Language  : C
*
* Author    : Rishith Rao, 
* GitHub ID : rishithrao57 
* Date      : 7 June 2020
*
**/

int main(void) {
  int sudoku_temp[9][9];
  generate_sudoku_template(sudoku_temp);
  int i,j;
for(i=0;i<9;i++){
	for(j=0;j<9;j++){
		printf("%d ",sudoku_temp[i][j]);
	}
	printf("\n");
}

return 0;

}
