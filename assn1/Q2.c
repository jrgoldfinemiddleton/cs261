/* CS261- Assignment 1 - Q.2*/
/* Name: Jason Goldfine-Middleton
 * Date: 01/04/16
 * Solution description: A program demonstrating the difference between pass-by-value
 *                       and pass-by-reference.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a *= 2;
    
    /*Set b to half its original value*/
    *b /= 2;
    
    /*Assign a+b to c*/
    c = *a + *b;
    
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
    int x = 7;
    int y = 8;
    int z = 9;
    
    /*Print the values of x, y and z*/
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    /*Print the value returned by foo*/
    printf("foo(&x, &y, z) = %d\n", foo(&x, &y, z));
    
    /*Print the values of x, y and z again*/
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);

    /*Is the return value different than the value of z?  Why?*/

    /* Yes, since z was not passed by reference, its value could not
     * be changed from within foo().  c is a different variable and
     * its value did change inside the function.
     */

    return 0;
}
    
    
