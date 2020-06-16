#ifndef __OUTPUT_SUDOKU_TEST_H__
#define __OUTPUT_SUDOKU_TEST_H__
 
/**
 * Testing function which outputs a 9x9 int array sudoku to a CSV file.
 * 
 * Expected result: The function will write all of the elements in the file. 
 * 
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_sudoku_1(void);

/**
 * Testing function which outputs a 9x9 int array Sudoku with elements that are 
 * between 1 and 9.
 * 
 * Expected result: The function will write the character equivalent of their 
 * int value. 
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_sudoku_2(void);

/**
 * Testing function Sudoku with some elements that are -1. 
 * 
 * Expected result: The function will write the character ‘/’ where the -1 are 
 * supposed to be. 
 *  
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_sudoku_3(void);

/**
 * Testing function call with sudoku with some elements that are 10. 
 * 
 * Expected result: The function will write the character ‘:’ where the 10 are 
 * supposed to be. 
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_sudoku_4(void);

/**
 * Testing function which outputs a 9x8 int array sudoku to a CSV file.
 * 
 * Expected result: The function will write all of the elements in the file 
 * and fill the remaining column with empty space.
 * 
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_sudoku_5(void);

/**
 * Testing function which outputs a 8x9 int array sudoku to a CSV file.
 * 
 * Expected result: The function will write all of the elements in the file 
 * and fill the remaining row with empty space.
 *  
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_sudoku_6(void);

/**
 * Testing function which checks a the sudoku_type parameter if it is a six 
 * char long string.
 * 
 * Expected result: The function will write the entire string in the file 
 * name.
 *  
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_sudoku_type_1(void);

/**
 * Testing function which checks a the sudoku_type parameter if it is a five 
 * char long string.
 * 
 * Expected result: The function will write the entire string in the file 
 * name.
 *  
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_sudoku_type_2(void);

/**
 * Testing function which checks a the sudoku_type parameter if it is a seven 
 * char long string.
 * 
 * Expected result: The function will write only the six first strings in the file 
 * name.
 *  
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_sudoku_type_3(void);

/**
 * Testing function which checks at the difficulty level parameter when it's 0.
 * 
 * Expected result: The function will write only the "_easy_" on the file name. 
 *  
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_diff_lvl_1(void);

/**
 * Testing function which checks at the difficulty level parameter when it's 1.
 * 
 * Expected result: The function will write only the "_normal_" on the file name. 
 *  
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_diff_lvl_2(void);

/**
 * Testing function which checks at the difficulty level parameter when it's 2.
 * 
 * Expected result: The function will write only the "_hard_" on the file name. 
 *  
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_diff_lvl_3(void);

/**
 * Testing function which checks at the difficulty level parameter when it's 3.
 * 
 * Expected result: The function will write only the "_very_hard_" on the file name. 
 *  
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_diff_lvl_4(void);

/**
 * Testing function which checks at the difficulty level parameter when it's -1.
 * 
 * Expected result: The function will write only the "_error_" on the file name. 
 *  
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_diff_lvl_5(void);

/**
 * Testing function which checks at the difficulty level parameter when it's 4.
 * 
 * Expected result: The function will write only the "_error_" on the file name. 
 *  
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_diff_lvl_6(void);

/**
 * Testing function which checks at the output_count parameter when it's 0.
 * 
 * Expected result: The function will check if the file name writes 0 ay the 
 * end of the file name. 
 *  
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_output_count_1(void);

/**
 * Testing function which checks at the output_count parameter when it's 999.
 * 
 * Expected result: The function will check if the file name writes 999 ay the 
 * end of the file name. 
 *  
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_output_count_2(void);

/**
 * Testing function which checks at the output_count parameter when it's -99.
 * 
 * Expected result: The function will check if the file name writes -99 ay the 
 * end of the file name. 
 *  
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_output_count_3(void);

/**
 * Testing function which checks at the output_count parameter when it's 1000.
 * 
 * Expected result: The function will check if the file name writes 0 at the 
 * end of the file name. 
 *  
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_output_count_4(void);

/**
 * Testing function which checks at the output_count parameter when it's -999.
 * 
 * Expected result: The function will check if the file name writes 0 at the 
 * end of the file name. 
 *  
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_output_count_5(void);

/**
 * Function to compare a sudoku array with the content of a CSV file containing 
 * a Sudoku.
 * 
 * 
 * @param location File location to compare with the array.
 * @param type Type of the sudoku.
 * @param diff_lvl Difficulty level of the Sudoku.
 * @param count Count ot the number of Sudoku created.
 * @param sudoku Sudoku array to compare with the file.
 * 
 * @return FALSE if the Sudokus are different. TRUE if they are they have the same values.
 */
_Bool verify_sudoku_file(int [][9], char *, int, int, char*);

/**
 * 
 * Function to compare a file name with the input parameters * 
 * 
 * @param location File location to compare with the array.
 * @param type Type of the sudoku.
 * @param diff_lvl Difficulty level of the Sudoku.
 * @param count Count ot the number of Sudoku created.
 * @param sudoku Sudoku array to compare with the file.
 * 
 * @return FALSE if the Sudokus are different. TRUE if they are they have the same values.
 */
_Bool verify_sudoku_file_name(int [][9], char *, int, int, char*);

#endif
