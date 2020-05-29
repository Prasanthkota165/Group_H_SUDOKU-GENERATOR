#ifndef 
   #define ROWS 9
   #define COLS 9
#endif  

int [] inputSudoku(int no_sudoku, int diff_level);
void generateSudokuTemplate(sudoku_temp[ROWS][COLS]);
void rearrangeColsRows(int sudoku_temp[ROWS][COLS], rearranged_sudoku_temp[ROWS][COLS]);
bool testSudokuRules(int test_sudoku[ROWS][COLS]);
void applyMask(int test_sudoku[ROWS][COLS], int diff_level, masked_sudoku[ROWS][COLS]);
bool applySolver(int sudoku_puzzle [ROWS][COLS]);
void outputSudoku(int sudoku_puzzle [ROWS][COLS], int sudoku_solution [ROWS][COLS]);
