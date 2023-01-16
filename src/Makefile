CC = gcc
CFLAGS=-std=c11 -pedantic -Wall -Werror -Wextra
CCOV = -fprofile-arcs -ftest-coverage
SOURSE_FILE = source/*.c source/calculator.h
COVFLAGS = --coverage
LDFLAGS = -lgcov
TFLAGS = -lcheck
#ASAN = -g -fsanitize=address

all: clean install run

install:
	sh install_script.sh

uninstall:
	rm -rf source/build

dvi:
	open readme.txt

dist:
	sh dist.sh

run:
	open source/build/smart_calc.app

test:
	$(CC) $(CFLAGS) $(ASAN) $(CCOV) $(SOURSE_FILE) -o test $(TFLAGS)
	./test

gcov_report:
	$(CC) $(ASAN) $(GFLAGS) $(CCOV) $(SOURSE_FILE) $(TFLAGS) -o ./htmlreport.out
	./htmlreport.out
	lcov -t "htmlreport" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

check:
	cppcheck --enable=all --force source/*.c source/calculator.h
	clang-format -n source/*.c
	clang-format -n source/*.h

leakscheck: test
	leaks --atExit -- ./test
#	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test


clean:
	rm -rf *.css index.html *.gcno *.gcda *.out *.info test report *.dSYM *.gcov build *.gch

fclean:
	rm -rf ./source/*.o
	rm -rf ./source/SmartCalc_dist
	rm -rf ./source/SmartCalc.tar
	rm -rf source/build
	rm test

rebuild: clean all

.PHONY : dvi clean run test gcov_report install uninstall