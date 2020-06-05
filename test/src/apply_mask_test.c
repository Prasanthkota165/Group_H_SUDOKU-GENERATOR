#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "../../src/apply_mask.c"

/**
* apply_mask_test 
* --------------- 
* This program tests apply_mask function
* Language C
* Author Gabriel Seyoum, Group H member
* Date May 31, 2020
*/

int main()
{  int masked_sudoku [9][9], diff_level [4] = {0, 1, 2, 3};
   
   int array_size = sizeof diff_level / sizeof *diff_level;
   
   int rearranged_sudoku [9][9] = {{1, 2, 3, 4, 5, 6, 7, 8, 9},
                                   {4, 5, 6, 7, 8, 9, 1, 2, 3},
                                   {7, 8, 9, 1, 2, 3, 4, 5, 6},
                                   {2, 3, 1, 5, 6, 4, 8, 9, 7},
                                   {5, 6, 4, 8, 9, 7, 2, 3, 1},
                                   {8, 9, 7, 2, 3, 1, 5, 6, 4},
                                   {3, 1, 2, 6, 4, 5, 9, 7, 8},
                                   {6, 4, 5, 9, 7, 8, 3, 1, 2},
                                   {9, 7, 8, 3, 1, 2, 6, 4, 5}};

    for(int i = 0; i < array_size; i++){
        apply_mask(rearranged_sudoku, diff_level [i], masked_sudoku);

        printf("\n------Numbers Masked------\n");
        for(int k = 0; k < 9; k++){
            for(int m = 0; m < 9; m++){
                printf(" %d ", masked_sudoku[k][m]);
            }
            printf("\n");
        }

    }

  return 0;
}

