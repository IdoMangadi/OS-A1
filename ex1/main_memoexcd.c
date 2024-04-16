#include <stdio.h>

int main(){

    // exceeding memory:
    int *ptr = 0x70707070;
    int val = *ptr;

    printf("In address: %p, value is: %d", (void *)ptr, val);
    
    return 0;
}