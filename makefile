FLAGS = -Wall -g

.PHONY: all clean ex1 ex2 ex3 ex4 ex5 ex6

all: ex1 ex2 ex3 ex4 ex5 ex6

ex1:
	make -C ex1 all

ex2:
	make -C ex2 all

ex3:
	make -C ex3 all

ex4: 
	make -C ex4 all

ex5:
	make -C ex5 all

ex6:
	make -C ex6 all

# Cleaning:
clean:
	make -C ex1 clean
	make -C ex2 clean
	make -C ex3 clean
	make -C ex4 clean
	make -C ex5 clean
	make -C ex6 clean