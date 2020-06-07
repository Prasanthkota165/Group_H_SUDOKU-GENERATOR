						*** Welcome to the Readme file ***
				This file tells you how to generate Sudoku Patterns from the repository
			=====================================================================================
Assuming that any IDE to run C programs install in your PC/Laptop

1. Firstly, Clone the GitHub Repository with the URL, https://github.com/Prasanthkota165/Group_H_SUDOKU-GENERATOR.git
   (OR) Download the zip file from the GitHub URL given above.

2. After the clone, go the Group_H_SUDOKU-GENERATOR folder and run the command "make clean" first in the terminal.

3. To run the project, give the command "make sudoku" in the terminal.

3. An input message will appear requesting:
	a)The number of Sudoku puzzles (for Release1, it is just "1");and
	b)The Sudoku puzzle's difficulty level.

4. You can request a maximum of 40 Sudokus per software run.

5. Their are 4 difficulty levels:
	a) Easy: 	40 numbers are shown on the puzzle
	b) Medium:	34 numbers are shown on the puzzle
	c) Hard:	28 numbers are shown on the puzzle 
	d) Very Hard:	24 numbers are shown on the puzzle

6. The output of the program will generate pairs of .CSV files equal to the number of requested puzzles:
	a) Sudoku puzzle;
	b) Sudoku answer; 

	For example, if the input request is ten hard Sudoku puzzles, the the program will generate 
	ten Sudoku puzzles and their ten respective Sudoku solutions.
