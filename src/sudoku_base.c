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

          = inputSudoku(&no_sudoku, &diff_level);

       generateSudokuTemplate(sudoku_template[ROWS][COLS]);

       rearrangeColsRows(sudoku_template[ROWS][COLS], rearranged_sudoku[ROWS][COLS]);
   
       if (testSudokuRules(rearranged_sudoku[ROWS][COLS])){
           applyMask(rearranged_sudoku[ROWS][COLS], diff_level, masked_sudoku[ROWS][COLS]);
       }
       else{
          generateSudokuTemplate(sudoku_template[ROWS][COLS]);
       }
   
 
       if (applySolver(masked_sudoku[ROWS][COLS])){
           outputSudoku(masked_sudoku[ROWS][COLS], sudoku_solution [ROWS][COLS]);
       }else
       {
           applyMask(rearranged_sudoku[ROWS][COLS], diff_level, masked_sudoku[ROWS][COLS]);
       }

   }


   return 0;
}

