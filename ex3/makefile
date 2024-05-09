FLAGS = -Wall -g

#need to use export in order to link properly export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./Poisson
.PHONY: all clean

all: Poisson

# main:
Poisson: PoissonMain.o libpoisson.so
	gcc $(FLAGS) $^ -lm -o $@

PoissonMain.o: PoissonMain.c Poisson3.h
	gcc $(FLAGS) -c $<
#lib: 
libpoisson.so: Poisson3.o
	gcc -shared -Wall -o $@ $^

Poisson3.o: Poisson3.c
	gcc $(FLAGS) -fPIC -c $^ 

# Cleaning:
clean:
	rm -f Poisson *.o *.so