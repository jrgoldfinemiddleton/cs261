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
    int initCap = 10;
    DynArr *pStack;

    /* assert(s != NULL); */

    pStack = newDynArr(initCap);

    for (; *s; ++s) {
        if (*s == '(' || *s == '{' || *s == '[')
            pushDynArr(pStack, *s);
        else if ((*s == ')' && (isEmptyDynArr(pStack) || topDynArr(pStack) != '(')) ||
                 (*s == '}' && (isEmptyDynArr(pStack) || topDynArr(pStack) != '{')) ||
                 (*s == ']' && (isEmptyDynArr(pStack) || topDynArr(pStack) != '['))) {
            deleteDynArr(pStack);
            pStack = NULL;
            return 0;
        }
        else if (*s == ')' || (*s == '}') || (*s == ']'))
            popDynArr(pStack);
    }

    if (!isEmptyDynArr(pStack))
        return 0;

    deleteDynArr(pStack);
    pStack = NULL;

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

