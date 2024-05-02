FLAGS = -Wall -g 
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99
GCOV_FLAGS = --coverage 

.PHONY: all clean

all: main_dijkstra

# mains:
main_dijkstra: main_dijkstra.c 
	gcc $(FLAGS) $(GCOV_FLAGS) $^ -o $@

valgrind: main_dijkstra
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./main_dijkstra

coverage: main_dijkstra
	./main_dijkstra 
	gcov main_dijkstra.c > coverage_report.txt 2>&1
	
	

# Cleaning:
clean:
	rm -f main_dijkstra *.gcda *.gcno *.gcov coverage_report.txt