/* CS261- Assignment 1 - Q. 0*/
/* Name: Jason Goldfine-Middleton
 * Date: 01/04/16
 * Solution description: A program that reviews the use of pointers.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
    /*Print the value of the integer pointed to by iptr*/
    printf("%d\n", *iptr);
     
    /*Print the address pointed to by iptr*/
    printf("%p\n", iptr);
     
    /*Print the address of iptr itself*/
    printf("%p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 11;
    
    /*print the address of x*/
    printf("%p\n", &x);
    
    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*print the value of x*/
    printf("%d\n", x);
    
    return 0;
}
