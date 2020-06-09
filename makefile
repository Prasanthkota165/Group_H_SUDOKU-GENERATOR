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
generate_sudoku_template.o: src/generate_sudoku_template.c
	$(CC) -g $(INCLUDESUDOKU) -c ./src/generate_sudoku_template.c -o ./build/generate_sudoku_template.o
input_sudoku.o: src/input_sudoku.c
	$(CC) -g $(INCLUDESUDOKU) -c ./src/input_sudoku.c -o ./build/input_sudoku.o
rearrange_cols_rows.o: src/rearrange_cols_rows.c
	$(CC) -g $(INCLUDESUDOKU) -c ./src/rearrange_cols_rows.c -o ./build/rearrange_cols_rows.o
apply_mask.o: src/apply_mask.c
	$(CC) -g $(INCLUDESUDOKU) -c ./src/apply_mask.c -o ./build/apply_mask.o
sudoku_base.o: src/sudoku_base.c
	$(CC) -g $(INCLUDESUDOKU) -c ./src/sudoku_base.c -o ./build/sudoku_base.o

solver_sudoku.o: src/solver_sudoku.c
	$(CC) -g $(INCLUDESUDOKU) -c ./src/solver_sudoku.c -o ./build/solver_sudoku.o

sudoku: output_sudoku.o generate_sudoku_template.o input_sudoku.o rearrange_cols_rows.o apply_mask.o sudoku_base.o
	$(CC) -g -o bin/SUDOKU.exe  build/output_sudoku.o build/generate_sudoku_template.o build/input_sudoku.o build/rearrange_cols_rows.o build/apply_mask.o build/sudoku_base.o

#output_sudoku_test.o: test/src/output_sudoku_test.c
#	$(CC) -g $(INCLUDESUDOKU) -c test/src/output_sudoku_test.c -o ./build/output_sudoku_test.o
solver_sudoku_test.o: test/src/solver_sudoku_test.c
	$(CC) -g $(INCLUDESUDOKU) -c test/src/solver_sudoku_test.c -o ./build/solver_sudoku_test.o


#testoutput : output_sudoku_test.o output_sudoku.o
#		$(CC) -g -o bin/SUDOKU_OUTPUT.exe ./build/output_sudoku_test.o ./build/output_sudoku.o

testsolver : solver_sudoku_test.o solver_sudoku.o
		$(CC) -g -o bin/SUDOKU_SOLVER_TEST.exe ./build/solver_sudoku_test.o ./build/solver_sudoku.o
			
#TARGET TO COMPILE EVERYTHING (ABP SIMULATOR + TESTS TOGETHER)
#all: snakes tests

#CLEAN COMMANDS
clean: 
	rm -f bin/* build/* output/*
