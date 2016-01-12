/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */		

    int initCap = 10;
    char c;
    DynArr *pStack;

    /* assert(s != NULL); */

    pStack = newDynArr(initCap);

    /* loop through string */
    for (c = nextChar(s); c ; c = nextChar(s)) {
        if (c == '(' || c == '{' || c == '[')
            /* add opening parens to stack */
            pushDynArr(pStack, c);
        else if ((c == ')' && (isEmptyDynArr(pStack) || topDynArr(pStack) != '(')) ||
                 (c == '}' && (isEmptyDynArr(pStack) || topDynArr(pStack) != '{')) ||
                 (c == ']' && (isEmptyDynArr(pStack) || topDynArr(pStack) != '['))) {
            /* no matching opening parenthesis */
            deleteDynArr(pStack);
            return 0;
        }
        else if (c == ')' || (c == '}') || (c == ']'))
            /* matching opening parenthesis */
            popDynArr(pStack);
    }

    if (!isEmptyDynArr(pStack)) {
        /* more opening parens than closing */
        deleteDynArr(pStack);
        return 0;
    }

    /* all open parens matched closing parens in balanced order */
    deleteDynArr(pStack);
    return 1;
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

