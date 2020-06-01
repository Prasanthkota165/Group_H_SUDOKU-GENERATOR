#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "../../src/apply_mask.c"

/**
* apply_mask_test 
* --------------- 
* It tests apply_mask function
* Language C
* Author Gabriel Seyoum, Group-H member, student # 100333091
* Date May 31, 2020
*/

int main()
{  int masked_sudoku [9][9], number_shown = 28;
   int rearranged_sudoku [9][9] = {{1, 2, 3, 4, 5, 6, 7, 8, 9},
                                   {4, 5, 6, 7, 8, 9, 1, 2, 3},
                                   {7, 8, 9, 1, 2, 3, 4, 5, 6},
                                   {2, 3, 1, 5, 6, 4, 8, 9, 7},
                                   {5, 6, 4, 8, 9, 7, 2, 3, 1},
                                   {8, 9, 7, 2, 3, 1, 5, 6, 4},
                                   {3, 1, 2, 6, 4, 5, 9, 7, 8},
                                   {6, 4, 5, 9, 7, 8, 3, 1, 2},
                                   {9, 7, 8, 3, 1, 2, 6, 4, 5}};


     apply_mask(rearranged_sudoku, number_shown, masked_sudoku);

     printf("--------Masked Sudoku -----\n");
     for(int k = 0; k < 9; k++){
     for(int m = 0; m < 9; m++){
       printf("%d ", masked_sudoku[k][m]);
     }
      printf("\n");
     }

  return 0;
}
