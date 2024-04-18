FLAGS = -Wall -g

.PHONY: all clean

all: main_stckof main_zerodiv main_memoexcd

# mains:
main_stckof: main_stckof.c
	gcc $(FLAGS) $^ -o $@
main_zerodiv: main_zerodiv.c
	gcc $(FLAGS) $^ -o $@
main_memoexcd: main_memoexcd.c
	gcc $(FLAGS) $^ -o $@

# Cleaning:
clean:
	rm -f main_stckof main_zerodiv main_memoexcd *.o *.out