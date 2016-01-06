/* CS261- Assignment 1 - Q. 0*/
/* Name: Jason Goldfine-Middleton
 * Date: 01/04/16
 * Solution description: A program that reviews the use of pointers.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
    /*Print the value of the integer pointed to by iptr*/
    printf("Value of integer pointed to by iptr: %d\n", *iptr);
     
    /*Print the address pointed to by iptr*/
    printf("Address of integer pointed to by iptr: %p\n", iptr);
     
    /*Print the address of iptr itself*/
    printf("Address of iptr: %p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 11;
    
    /*print the address of x*/
    printf("Address of x: %p\n", &x);
    
    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*print the value of x*/
    printf("Value of x: %d\n", x);
    
    return 0;
}
