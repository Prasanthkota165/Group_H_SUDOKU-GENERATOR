#include <stdio.h>
#include "../include/sudoku.h"

int main(void){
    int no_sudoku, diff_level;
    int sudoku_template [ROWS][COLS];
    int rearranged_sudoku[ROWS][COLS];
    bool tester;
    int masked_sudoku[ROWS][COLS];
    int sudoku_solution [ROWS][COLS];
  
    
  for(int i = 0; i < no_sudoku; i++){

          = inputSudoku();

       generateSudokuTemplate(sudoku_template);

       rearrangeColsRows(sudoku_template, rearranged_sudoku);
   
       if (testSudokuRules(rearranged_sudoku)){
           applyMask(rearranged_sudoku, diff_level, masked_sudoku);
       }
       else{
          generateSudokuTemplate(sudoku_template);
       }
   
 
       if (applySolver(masked_sudoku)){
           outputSudoku(masked_sudoku, sudoku_solution);
       }else
       {
           applyMask(rearranged_sudoku, diff_level, masked_sudoku);
       }

   }


   return 0;
}

