FLAGS = -Wall -g -pg

.PHONY: all clean profiling

all: msas_n msas_n2 msas_n3

# mains:
msas_n: msas_n.c
	gcc $(FLAGS) $^ -o $@
msas_n2: msas_n2.c
	gcc $(FLAGS) $^ -o $@
msas_n3: msas_n3.c
	gcc $(FLAGS) $^ -o $@

profiling: msas_n msas_n2 msas_n3
# n:
	@echo "---------profiling for n---------"
	./msas_n 5 100
	gprof msas_n gmon.out > a_n_100.txt
	./msas_n 5 1000
	gprof msas_n gmon.out > a_n_1000.txt
	./msas_n 5 10000
	gprof msas_n gmon.out > a_n_10000.txt
# n^2:
	@echo "---------profiling for n^2-------"
	./msas_n2 5 100
	gprof msas_n2 gmon.out > a_n2_100.txt
	./msas_n2 5 1000
	gprof msas_n2 gmon.out > a_n2_1000.txt
	./msas_n2 5 10000
	gprof msas_n2 gmon.out > a_n2_10000.txt
# n^3:
	@echo "---------profiling for n^3-------";
	./msas_n3 5 100;
	gprof msas_n3 gmon.out > a_n3_100.txt;
	./msas_n3 5 1000;
	gprof msas_n3 gmon.out > a_n3_1000.txt;
	./msas_n3 5 10000;
	gprof msas_n3 gmon.out > a_n3_10000.txt;

# Cleaning:
clean:
	rm -f msas_n msas_n2 msas_n3 