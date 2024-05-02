#include <stdio.h> 
#include <stdlib.h> 

#define MIN_VALUE -25
#define MAX_VALUE 74

/**
 * Finds the maximum subarray sum using a brute-force approach.
 *
 * This function takes an array of integers and its size as input
 * and returns the maximum sum of a contiguous subarray within the array.
 * The function uses a brute-force approach with a time complexity of O(n^2).
 *
 * @param arr An array of integers.
 * @param size The size of the array.
 * @return The maximum sum of a contiguous subarray.
 */
int max_sub_array_sum_n2(int arr[], int size) {
    int max_sum = arr[0]; // Initialize the maximum sum to the first element
    for (int i = 0; i < size; i++) {
        int current_sum = 0;
        for (int j = i; j < size; j++) {
            current_sum += arr[j]; // Calculate the sum of the subarray from i to j
            if (current_sum > max_sum) {
                max_sum = current_sum; // Update the maximum sum if the current sum is greater
            }
        }
    }
    return max_sum;
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
        fprintf(stderr,"Please enter only two numbers.");
        return 1;
    }

    unsigned int rand_seed = atoi(argv[1]);  // represent the seed to srand.
    int size = atoi(argv[2]);  // represent the size of the array.
    if(size < 0){
        fprintf(stderr,"Size cant be less than 0");
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
    int res = max_sub_array_sum_n2(arr, size);
    printf("For seed: %u, and size: %d, result is: %d\n", rand_seed, size, res);
    free(arr);
    return 0;
}