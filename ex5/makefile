FLAGS = -Wall -g

.PHONY: all clean

all: msas_n msas_n2 msas_n3

# mains:
msas_n: msas_n.c
	gcc $(FLAGS) $^ -o $@
msas_n2: msas_n2.c
	gcc $(FLAGS) $^ -o $@
msas_n3: msas_n3.c
	gcc $(FLAGS) $^ -o $@

# Cleaning:
clean:
	rm -f msas_n msas_n2 msas_n3 