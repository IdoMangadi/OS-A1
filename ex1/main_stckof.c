#include <stdio.h>

long over_flow(long x, long y);

int main(){
    long a = 10;
    long b = 10;
    long stack_over_flow = over_flow(a, b);  // inforcing stack over flow

    printf("Recursice value: %ld\n", stack_over_flow);

    return 0;
}

/**
 * Recursive function to inforce stack over flow.
*/
long over_flow(long x, long y){
    long z = 10;
    long w = 10;
    return over_flow(x, y) + over_flow(z, w);
}