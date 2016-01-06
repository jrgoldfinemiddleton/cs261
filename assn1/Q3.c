/* CS261- Assignment 1 - Q.3*/
/* Name: Jason Goldfine-Middleton
 * Date: 01/04/16
 * Solution description: A program that sorts an array of integers.
 */
 
#include <stdio.h>
#include <stdlib.h>

void sort(int* number, int n){
    int max;
    int i;
    int tmp;

    /*Sort the given array number , of length n*/
    for (--n; n >= 0; --n) {
        max = 0;

        /* find index with max value*/
        for (i = 0; i <= n; ++i)
            if (number[max] < number[i])
                max = i;

        /* swap max value with end of unsorted subinterval */
        if (max != n) {
            tmp = number[n];
            number[n] = number[max];
            number[max] = tmp;
        }
    }
}

int main(){
    /*srand((unsigned int) time(0));*/

    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    int i;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int* nums = malloc(n * sizeof(int));
    
    /*Fill this array with random numbers between 0 and n, using rand().*/
    for (i = 0; i != n; ++i)
        nums[i] = rand() % (n + 1);
    
    /*Print the contents of the array.*/
    for (i = 0; i != n; ++i)
        printf("%d ", nums[i]);
    printf("\n");

    /*Pass this array along with n to the sort() function.*/
    sort(nums, n);
    
    /*Print the contents of the array.*/    
    for (i = 0; i != n; ++i)
        printf("%d ", nums[i]);
    printf("\n");
    
    return 0;
}
