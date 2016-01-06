/*********************************************************************
** Program Filename: main.c
** Author: Jason Goldfine-Middleton
** Date: 01/03/16
** Description: A simple program to convert temperatures from Celsius
**              to Fahrenheit.
** Input: stdin, scanf(), getchar(), getc()
** Output: stdout, printf()
*********************************************************************/

#include <ctype.h>      /* tolower() */
#include <stdbool.h>    /* bool, true, false */
#include <stdio.h>      /* printf(), scanf(), getchar(), getc(), EOF */
#include <stdlib.h>     /* EXIT_SUCCESS */


void clrstrm(FILE *stream);
double ctof(double cels);


int main(int argc, char *argv[])
{
    double cels;
    bool done = false;

    do {
        printf("Enter a temperature in Celsius: ");
        scanf("%lf", &cels);
        clrstrm(stdin);

        printf("%.3lf C is equivalent to %.3lf F\n", cels, ctof(cels));
 
        printf("Would you like to convert another temperature (y/n)? ");
        if (tolower(getchar()) != 'y')
            done = true;
        else
            clrstrm(stdin);

    } while (!done);

    return EXIT_SUCCESS;
}


/*
 * clrstrm(): Removes the next line of input or all characters left on a stream,
 * whichever comes first.
 */
void clrstrm(FILE *stream)
{
    int cur;
    while ((cur = getc(stream)) != EOF && cur != '\n');
}


/*
 * ctof(): Converts a temperature in Celsius to Fahrenheit and returns it.
 */
double ctof(double cels)
{
    return (9.0 / 5.0) * cels + 32.0;
}