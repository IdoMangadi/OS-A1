FLAGS = -Wall -g 

.PHONY: all clean

all: Poisson

# mains:
Poisson: Poisson.c 
	gcc $(FLAGS) $^ -lm -o $@


# Cleaning:
clean:
	rm -f Poisson