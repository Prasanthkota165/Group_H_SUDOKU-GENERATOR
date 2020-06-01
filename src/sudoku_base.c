#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../include/sudoku.h"


int main(void){
    int no_sudoku, numbers_tobe_shown, diff_level;
    int sudoku_template[ROWS][COLS];
    int rearranged_sudoku[ROWS][COLS];
    bool tester;
    int masked_sudoku[ROWS][COLS];
    int sudoku_solution [ROWS][COLS];
  
   
  for(int i = 0; i < no_sudoku; i++){

          = input_sudoku();

    switch(diff_level){
        case 0:

            numbers_tobe_shown = 40;    //Amount of number that will be shown on Sodoku game is 40
            break;
         
        case 1:

            numbers_tobe_shown = 34;    //Amount of number that will be shown on Sodoku game is 34
            break;
        
        case 2:

            numbers_tobe_shown = 28;    //Amount of number that will be shown on Sodoku game is 28
            break;
        
        case 3:

            numbers_tobe_shown = 24;    //Amount of number that will be shown on Sodoku game is 24
            break;
        
        deafult:
            printf("Wrong difficulty level value");    //Dificulty level is not 0, 1, 2 or 3
        }
    }

       generate_sudoku_template(sudoku_template);

       rearrange_cols_rows(sudoku_template, rearranged_sudoku);
   
       if (test_sudoku_rules(rearranged_sudoku)){
           apply_mask(rearranged_sudoku, numbers_tobe_shown, masked_sudoku);
       }
       else{
          generate_sudoku_template(sudoku_template);
       }
   
 
       if (apply_solver(masked_sudoku)){
           output_sudoku(masked_sudoku, sudoku_solution, diff_level);
       }
       else{
           apply_mask(rearranged_sudoku, numbers_tobe_shown, masked_sudoku);
       }

   }


   return 0;
}

