#ifndef __TEST_SUDOKU_TEST_H__
#define __TEST_SUDOKU_TEST_H__
/**
 * Testing function tests for any errors in rows, columns and 3x3 matrices.
 * 
 * @param[in] sudoku[9][9] input parameter to the function rearrange_rows_cols 
 *                          function.
 *
 * @param[in] rearranged_sudoku[9][9] output parameter to the function 
 *                                      rearrange_rows_cols function.
 *  
 * @return  True if the test passed. False if the test failed
 *  
 */ 
_Bool main_test(int [9][9],int [9][9]);

/**
 * Testing function tests for any errors in rows.
 * 
 * @param[in] sudoku[9][9] input parameter to the function rearrange_rows_cols 
 *                              function.
 *
 * @param[in] rearranged_sudoku[9][9] output parameter to the function 
 *                                    rearrange_rows_cols function.
 *  
 * @return  True if the test passed. False if the test failed
 *  
 */
_Bool testing_rows(int [9][9],int [9][9]);

/**
 * Testing function tests for any errors in columns.
 * 
 * @param[in] sudoku[9][9] input parameter to the function rearrange_rows_cols 
 *                          function.
 *
 * @param[in] rearranged_sudoku[9][9] output parameter to the function 
 *                                      rearrange_rows_cols function.
 *  
 * @return  True if the test passed. False if the test failed
 *  
 */
_Bool testing_cols(int [9][9],int [9][9]);

/**
 * Testing function tests for any errors in 3x3 matrices.
 * 
 * @param[in] sudoku[9][9] input parameter to the function rearrange_rows_cols 
 *                          function.
 *
 * @param[in] rearranged_sudoku[9][9] output parameter to the function 
 *                                     rearrange_rows_cols function.
 *  
 * @return  True if the test passed. False if the test failed
 *  
 */
_Bool testing_3X3(int [9][9],int [9][9]);
#endif
