CC = gcc

#CALLING DECLARATION FILES LOCATION 
INCLUDESUDOKU = -I include

TESTBIN = cd ./test/bin;

#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME
bin_folder := $(shell mkdir -p bin)
build_folder := $(shell mkdir -p build)
output_folder := $(shell mkdir -p output)
test_bin_folder := $(shell mkdir -p test/bin)
test_build_folder := $(shell mkdir -p test/build)
test_output_folder := $(shell mkdir -p test/output)
test_log_folder := $(shell mkdir -p test/log)

#TARGET TO COMPILE ALL SUDOKU TOGETHER 
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
test_sudoku.o : src/test_sudoku.c
	$(CC) -g $(INCLUDESUDOKU) -c ./src/test_sudoku.c -o ./build/test_sudoku.o
solver_sudoku.o : src/solver_sudoku.c
	$(CC) -g $(INCLUDESUDOKU) -c ./src/solver_sudoku.c -o ./build/solver_sudoku.o
sudoku_base.o: src/sudoku_base.c
	$(CC) -g $(INCLUDESUDOKU) -c ./src/sudoku_base.c -o ./build/sudoku_base.o

sudoku: output_sudoku.o generate_sudoku_template.o input_sudoku.o rearrange_cols_rows.o apply_mask.o test_sudoku.o solver_sudoku.o sudoku_base.o 
	$(CC) -g -o bin/SUDOKU.exe  build/output_sudoku.o build/generate_sudoku_template.o build/input_sudoku.o build/rearrange_cols_rows.o build/apply_mask.o build/test_sudoku.o build/solver_sudoku.o build/sudoku_base.o 

#TARGET TO RUN SUDOKU
runsudoku: 
		cd ./bin; ./SUDOKU.exe

#TARGET TO COMPILE AND RUN SUDOKU
runallsudoku: sudoku runsudoku
		

#TARGET TO COMPILE ALL TESTINGS TOGETHER
apply_mask_test.o : test/src/apply_mask_test.c
	$(CC) -g $(INCLUDESUDOKU) -c ./test/src/apply_mask_test.c -o ./test/build/apply_mask_test.o
generate_sudoku_template_test.o : test/src/generate_sudoku_template_test.c
	$(CC) -g $(INCLUDESUDOKU) -c ./test/src/generate_sudoku_template_test.c -o ./test/build/generate_sudoku_template_test.o
input_sudoku_test.o : test/src/input_sudoku_test.c
	$(CC) -g $(INCLUDESUDOKU) -c ./test/src/input_sudoku_test.c -o ./test/build/input_sudoku_test.o
output_sudoku_test.o : test/src/output_sudoku_test.c
	$(CC) -g $(INCLUDESUDOKU) -c ./test/src/output_sudoku_test.c -o ./test/build/output_sudoku_test.o
solver_sudoku_test.o : test/src/solver_sudoku_test.c
	$(CC) -g $(INCLUDESUDOKU) -c ./test/src/solver_sudoku_test.c -o ./test/build/solver_sudoku_test.o
test_rearrange_cols_rows.o : test/src/test_rearrange_cols_rows.c
	$(CC) -g $(INCLUDESUDOKU) -c ./test/src/test_rearrange_cols_rows.c -o ./test/build/test_rearrange_cols_rows.o
test_sudoku_test.o : test/src/test_sudoku_test.c
	$(CC) -g $(INCLUDESUDOKU) -c ./test/src/test_sudoku_test.c -o ./test/build/test_sudoku_test.o

testapplymask : apply_mask_test.o apply_mask.o
		$(CC) -g -o ./test/bin/TEST_APPLY_MASK.exe ./test/build/apply_mask_test.o ./build/apply_mask.o
testsudokutemplate : generate_sudoku_template_test.o generate_sudoku_template.o
		$(CC) -g -o ./test/bin/TEST_SUDOKU_TEMPLATE.exe ./test/build/generate_sudoku_template_test.o ./build/generate_sudoku_template.o
testinput :input_sudoku_test.o input_sudoku.o
		$(CC) -g -o ./test/bin/TEST_SUDOKU_INPUT.exe ./test/build/input_sudoku_test.o ./build/input_sudoku.o
testoutput : output_sudoku_test.o output_sudoku.o
		$(CC) -g -o ./test/bin/TEST_SUDOKU_OUTPUT.exe ./test/build/output_sudoku_test.o ./build/output_sudoku.o
testsolver : solver_sudoku_test.o solver_sudoku.o
		$(CC) -g -o ./test/bin/TEST_SUDOKU_SOLVER.exe ./test/build/solver_sudoku_test.o ./build/solver_sudoku.o
testrearrange : test_rearrange_cols_rows.o rearrange_cols_rows.o
		$(CC) -g -o ./test/bin/TEST_REARRANGE_COL_ROW.exe ./test/build/test_rearrange_cols_rows.o ./build/rearrange_cols_rows.o
testsudokutest :  test_sudoku_test.o test_sudoku.o
		$(CC) -g -o ./test/bin/TEST_SUDOKU_TEST.exe ./test/build/test_sudoku_test.o.o ./build/test_sudoku_test.o

alltest : testapplymask testsudokutemplate testinput testoutput testsolver testrearrange testsudokutest

#TARGET TO RUN ALL TESTINGS TOGETHER
runtestapplymask : 
		$(TESTBIN) ./TEST_APPLY_MASK.exe
runtestsudokutemplate : 
		$(TESTBIN) ./TEST_SUDOKU_TEMPLATE.exe
runtestinput : 
		$(TESTBIN) ./TEST_SUDOKU_INPUT.exe
runtestoutput : 
		$(TESTBIN) ./TEST_SUDOKU_OUTPUT.exe
runtestsolver : 
		$(TESTBIN) ./TEST_SUDOKU_SOLVER.exe
runtestrearrange : 
		$(TESTBIN) ./TEST_REARRANGE_COL_ROW.exe
runtestsudokutest : 
		$(TESTBIN) ./TEST_SUDOKU_TEST.exe

runtest : runtestapplymask runtestsudokutemplate runtestinput runtestoutput runtestsolver runtestrearrange runtestsudokutest

#TARGET TO COMPILE AND RUN ALL TESTINGS
runalltest:  alltest runtest


#TARGET TO COMPILE EVERYTHING (SUDOKU GENERATOR + TESTS TOGETHER)
all : sudoku alltest

#TARGET TO RUN EVERYTHING (SUDOKU GENERATOR + TESTS TOGETHER)
run : runsudoku runtest

#TARGET TO COMPILE AND RUN EVERYTHING (SUDOKU GENERATOR + TESTS TOGETHER)
runall : run all

#CLEAN COMMANDS
clean: 
	rm -f bin/* build/* output/* test/bin/* test/build/* test/output/* test/log/*
