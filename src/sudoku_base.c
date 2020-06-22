/**
* @file sudoku_base.c 
*
* Purpose   : This is the main function to generate the sudoku puzzle and 
                solution.
*
* Language  : C
*
* GitHub link : https://github.com/Prasanthkota165/Group_H_SUDOKU-GENERATOR
*
* Author    : Group H, Prasanth Kota 
*		       Mathieu Falardeau
*		       Rishith Rao
*		       Gabriel Seyoum
*		       
* Date      : 5 June 2020
*
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "../include/sudoku.h"

/**
 * @brief Primary function of the Sudoku Generator.
 * 
 * When running, the Sudoku Generator will follow these steps:
 *  
 * 1. The program begins by requesting the users two inputs: the difficulty 
 *     level of the Sudoku puzzles and the number of requested Sudoku puzzles. 
 *     To simplify the internal management of the difficulty level, the program 
 *     converts the input into int values:
 *          + The user can request a maximum of 40 Sudoku's per software run; and 
 *          + The difficulty levels are set as such:
 *          |Difficulty|Amount of numbers shown|
 *          |----------|-----------------------|
 *          |Easy      |40                     |
 *          |Medium    |34                     |
 *          |Hard      |28                     |
 *          |Very Hard |24                     |
 *
 * 2. Afterwards, the program will begin a loop where it will create Sudoku 
 *      solutions and puzzles until the number of requested Sudoku is reached. 
 *      For each instance of the loop, the program will go through three 
 *      different stages: Generating Sudoku Puzzle, Generating Sudoku Solution, 
 *      and Exporting Sudoku Puzzle and Solution.
 *
 * 3. Following the algorithm, a random Sudoku solution can be generated from 
 *      over six hundred billion different combinations. The Sudoku Solution is 
 *      then tested to validate its authenticity, if it fails, then the solution 
 *      is deleted and the algorithm is repeated until a valid Sudoku Solution 
 *      is created. 
 * 
 * 4. The Sudoku puzzle is generated by applying a masking pattern on the Sudoku 
 *      Solution. The masking pattern consists of randomly removing digits on 
 *      the Sudoku Solution until only a certain number of digits are left. The 
 *      number of digits left is determined by the difficulty level requested 
 *      by the user. Afterwards, a Solving Algorithm is applied on the puzzle 
 *      to determine if it can be solved. If it passes, then the puzzle is 
 *      valid. If not, then the masking pattern is repeated again until a valid 
 *      Sudoku Puzzle is created.
 *
 * 5. The data from both the puzzle and the solution are each individually 
 *      exported into two .CSV files. The naming convention of those files are:
 *          * sudoku_puzzle_lvl#_X.csv [1][2]
 *          * sudoku_solution_ lvl#_X.csv [1][2]  
 * 
 */
int main(void){

    /*Variables*/
    int no_sudoku, diff_level;
    int sudoku_template[ROWS][COLS];
    int rearranged_sudoku[ROWS][COLS];
    int masked_sudoku[ROWS][COLS];
    int sudoku_solution [ROWS][COLS];
    int solver_output [ROWS][COLS];
 

    srand(time(0)); /*Initialize the randomizer function*/

    /* Input the difficulty level and number of sudoku needed */
    input_sudoku(&diff_level,&no_sudoku);
    
    /*Loop according to the number of Sudokus to be created*/
    for (int i = 0; i < no_sudoku; i++){
        do{
            /* This function will generate the sudoku template */
            generate_sudoku_template(sudoku_template);

            /* Rearranging the sudoku template to generate different 
            combinations of sudoku */ 
            rearrange_cols_rows(sudoku_template, rearranged_sudoku);
        
        /*Tests the rearranged sudoku for sudoku rules*/
        }while(test_sudoku_rules(rearranged_sudoku));
     
        do{
            /* Masking the numbers on the rearranged sudoku template according 
            to the difficulty level provided */  
            apply_mask(rearranged_sudoku, diff_level, masked_sudoku);

                /*Verifies if the Sudoku puzzle is solvable*/
        }while(!solver_sudoku(masked_sudoku, solver_output));

        /* Finally, create the two .csv files (puzzle and solution) into the 
        output folder */
        output_sudoku(rearranged_sudoku, masked_sudoku, diff_level);
    }
    
    /*Final message of the program*/
    printf("Sudoku generator has finished creating %d sudoku(s).\n", no_sudoku);
    printf("Press enter to exit\n");
    getchar();

    return 0;
}

