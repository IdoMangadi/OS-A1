#include <stdio.h> 
#include <stdlib.h> 

#define MIN_VALUE -25
#define MAX_VALUE 74

/**
 * Finds the maximum subarray sum using Kadane's algorithm.
 *
 * This function takes an array of integers and its size as input
 * and returns the maximum sum of a contiguous subarray within the array.
 *
 * @param arr An array of integers.
 * @param size The size of the array.
 * @return The maximum sum of a contiguous subarray.
 */

int max_sub_array_sum_n(int *arr, int size){

    int max_current = arr[0];
    int max_global = arr[0];
    
    for (int i = 1; i < size; i++) {
        max_current = (arr[i] > max_current + arr[i]) ? arr[i] : max_current + arr[i];
        max_global = (max_current > max_global) ? max_current : max_global;
    }

    return max_global;
}

/**
 * Generating array of integers of size "size" using srand with "rand_seed" 
*/
void arr_gen(int *arr, int size, unsigned int rand_seed){
    srand(rand_seed);
    for(int i=0; i<size; i++){
        arr[i] = rand() % ((MAX_VALUE) - (MIN_VALUE) + 1) + (MIN_VALUE); // normalizing rand output to be between MAX_VALUE to MIN_VALUE
        // printf("%d ", arr[i]);
    }
    // printf("\n");
}


int main(int argc, char* argv[]){

    // Argument handling:
    if(argc != 3){
        fprintf(stderr,"Please enter only two numbers.\n");
        return 1;
    }

    unsigned int rand_seed = atoi(argv[1]);  // represent the seed to srand.
    int size = atoi(argv[2]);  // represent the size of the array.
    if(size < 0){
        fprintf(stderr,"Size cant be less than 0.\n");
        return 1;
    }

    // Array generating:
    int* arr = (int*)malloc(sizeof(int) * size);
    if(arr == NULL){
        fprintf(stderr,"Malloc failure.\n");
        return 1;
    }
    arr_gen(arr, size, rand_seed);

    // max sub array sum function:
    int res = max_sub_array_sum_n(arr, size);
    printf("For seed: %u, and size: %d, result is: %d\n", rand_seed, size, res);
    free(arr);
    return 0;
}
