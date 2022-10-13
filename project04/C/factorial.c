/**
* (Extension) factorial: Write a function that takes in an integer argument 
* and returns its factorial value as an integer, both recursively and iteratively.
*
* Scottie YANG Miaoyi
* Mar 11, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Recursively returns the factorial of a given integer. 
 * 
 * Parameters:
 * int n: the integer to compute the factorial of.
 *
 * Returns: the factorial of n.
 */
int factorial_recursive(int n){
    if (n == 0) 
        return 1; 
    return (n * factorial_recursive(n - 1)); 
}

/* (Extension) Iteratively returns the factorial of a given integer. 
 * 
 * Parameters:
 * int n: the integer to compute the factorial of.
 *
 * Returns: the factorial of n.
 */
int factorial_iterative(int n) 
{ 
    int result = 1, i; 
    for (i = 2; i <= n; i++) 
        result *= i; 
    return result; 
} 

int main (int argc, char **argv) {

    // Assign the factorial functions to calc variables.
	int (*calc)(const int);
    calc = &factorial_recursive;
    int (*calc2)(const int);
    calc2 = &factorial_iterative;

    // Run and (extension) TIME the recursive implementation.
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int result = (*calc)(strtol(argv[1], NULL, 10)); 
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The factorial is %d, to compute it RECURSIVELY takes %f seconds. \n", result, cpu_time_used);

    start = clock();
    int result2 = (*calc2)(strtol(argv[1], NULL, 10)); 
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The factorial is %d, to compute it ITERATIVELY takes %f seconds. \n", result2, cpu_time_used);

	return 0;
}