Organization: Carleton University, Ottawa, ON, Canada  
Authors:  
Mathieu Falardeau  
Gabriel Seyoum   
Prasanth Kota  
Rishith Rao  

Sudoku Generator software creates Sodoku puzzles of various difficulty levels, where an Easy game is only showing 40 numbers out of 81, whereas the Medium only showing 34, the Hard 28 and the Very Hard 24 numbers.

Files are organized as follow: /bin , /build , /data , /include , /lib , /output , /src , /test/src, /test/log , makefile , README

                             *** Welcome to the Readme file ***
          This file tells you how to generate Sudoku Patterns from the repository  

Assuming that any IDE to run C programs install in your PC/Laptop  

    Clone the GitHub Repository with the URL, https://github.com/Prasanthkota165/Group_H_SUDOKU-GENERATOR.git (OR) Download the zip file from the GitHub URL given above.

    Afterwards, go to the Group_H_SUDOKU-GENERATOR folder and run the command "make clean" first in the terminal.

    To run the project, give the command "make sudoku" in the terminal.  

    An input message will appear requesting:  
    a)The number of Sudoku puzzles (values from 1 to 40)  
    b)The Sudoku puzzle's difficulty level (values 0, 1, 2, or 3)  

    You can request a maximum of 40 Sudokus per software run.  

    Their are 4 difficulty levels where:   
    a) Easy: input '0'  
    b) Medium: input '1'  
    c) Hard: input '2'  
    d) Very Hard: input '3'  

    The output of the program will generate pairs of .CSV files equal to the number of requested puzzles:  
    a) Sudoku puzzle  
    b) Sudoku answer  

    For example, if the input request is ten hard Sudoku puzzles, the program will generate ten Sudoku puzzles and their ten respective Sudoku solutions.