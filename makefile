CC = gcc

#CALLING DECLARATION FILES LOCATION 
INCLUDESUDOKU = -I include

#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME
bin_folder := $(shell mkdir -p bin)
build_folder := $(shell mkdir -p build)
output_folder := $(shell mkdir -p output)

#TARGET TO COMPILE ALL THE TESTS TOGETHER 
output_sudoku.o: src/output_sudoku.c
	$(CC) -g $(INCLUDESUDOKU) -c ./src/output_sudoku.c -o ./build/output_sudoku.o

#output_sudoku_test.o: test/src/output_sudoku_test.c
#	$(CC) -g $(INCLUDESUDOKU) -c test/src/output_sudoku_test.c -o ./build/output_sudoku_test.o

#REST OF MAKEFILE TO BE COMPLETED
#main_top.o: top_model/main.cpp
#	$(CC) -g -c $(INCLUDECADMIUM) $(INCLUDEDESTIMES) top_model/main.cpp -o build/main_top.o
	
#main_subnet_test.o: test/main_subnet_test.cpp
#	$(CC) -g -c  $(INCLUDECADMIUM) $(INCLUDEDESTIMES) test/main_subnet_test.cpp -o build/main_subnet_test.o

#TARGET TO COMPILE ONLY ABP SIMULATOR
#sneaks: main_top.o message.o 
#	$(CC) -g -o bin/SNEAKS.OUT build/main_top.o build/message.o 

#test: main_subnet_test.o  message.o
#		$(CC) -g -o bin/SUBNET_TEST build/main_subnet_test.o build/message.o

testoutput : output_sudoku_test.o output_sudoku.o
		$(CC) -g -o bin/SUDOKU_OUTPUT.exe ./build/output_sudoku_test.o ./build/output_sudoku.o
			
#TARGET TO COMPILE EVERYTHING (ABP SIMULATOR + TESTS TOGETHER)
#all: snakes tests

#CLEAN COMMANDS
clean: 
	rm -f bin/* build/* output/*