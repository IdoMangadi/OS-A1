#include  <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int isNumber(const char *str) {
    char *end;
    strtod(str,&end);

    // If there's any leftover characters in the string, it's not a number
    while (*end) {
        if (!isspace((unsigned char)*end)) return 0;
        end++;
    }

    return 1;
}
int main(int argc, char** argv){
    if(argc != 3){
        printf("Error\n");
        return -1;
    }
    if (!isNumber(argv[1]) || !isNumber(argv[2]))
    {
        printf("Both arguments must be numbers!\n");
        return -1;
    }
    long double lambda = strtold(argv[1],NULL);
    if (lambda <=0)
    {
        printf("Lambda must be greater than zero!\n");
        return -1;
    }
    unsigned long int k = atoi(argv[2]);
    if (k<0)
    {
        printf("k must be at least zero!\n");
        return -1;
    }
     long double res = pow(lambda, k) * expf(-lambda) / tgamma(k+1); //the tgamma function is the gamma function, notice that the gamma function is defined as gamma(n) = (n-1)! for natural n>0
    printf("Poisson(%Lf, %ld) = %.12Lf\n", lambda, k, res);
    return 0;
}
