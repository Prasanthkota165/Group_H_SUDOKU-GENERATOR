#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../include/sudoku.h"


int main(void){
    int no_sudoku, diff_level;
    
    int sudoku_template[ROWS][COLS];
    int rearranged_sudoku[ROWS][COLS];
    _Bool tester;
    int masked_sudoku[ROWS][COLS];
    int sudoku_solution [ROWS][COLS];
    int c;
  
    input_sudoku(&diff_level,&no_sudoku);
    printf("num sudoku: %d,\n diff level: %d",no_sudoku,diff_level);
    scanf("%d",&c);

    //for(int i = 0; i < no_sudoku; i++){

          

    
    //}

        generate_sudoku_template(sudoku_template);
        for(int k = 0; k < 9; k++){
            for(int m = 0; m < 9; m++){
                printf("%d ", sudoku_template[k][m]);
            }
            printf("\n");
         }
        scanf("%d",&c);
        rearrange_cols_rows(sudoku_template, rearranged_sudoku);

        for(int k = 0; k < 9; k++){
            for(int m = 0; m < 9; m++){
                printf("%d ", rearranged_sudoku[k][m]);
            }
            printf("\n");
        }
        scanf("%d",&c);
       //if (test_sudoku_rules(rearranged_sudoku)){
        apply_mask(rearranged_sudoku, diff_level, masked_sudoku);
        for(int k = 0; k < 9; k++){
            for(int m = 0; m < 9; m++){
                printf("%d ", masked_sudoku[k][m]);
            }
            printf("\n");
        }
        scanf("%d",&c);
       //}
       //else{
        //  generate_sudoku_template(sudoku_template);
       //}
   

      // if (apply_solver(masked_sudoku)){
           output_sudoku(rearranged_sudoku, masked_sudoku, diff_level);
      // }
      // else{
      //     apply_mask(rearranged_sudoku, diff_level, masked_sudoku);
      // }

  // }


   return 0;
}

