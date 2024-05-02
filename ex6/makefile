FLAGS = -Wall -g

.PHONY: all clean

all: findPhone add2PB

# mains:
findPhone: findPhone.c
	gcc $(FLAGS) $^ -o $@
add2PB: add2PB.c
	gcc $(FLAGS) $^ -o $@


# Cleaning:
clean:
	rm -f findPhone add2PB *.o *.out