#include <stdio.h>
#include "../../src/generate_sudoku_template.c"

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
