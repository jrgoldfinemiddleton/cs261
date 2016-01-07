/* CS261- Assignment 1 - Q.5*/
/* Name: Jason Goldfine-Middleton
 * Date: 01/04/16
 * Solution description: A program that converts a string to StUdLy CaPs.
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void studly(char* word){
    int i = 0;  /* current position */
    char c;     /* current character */

     /*Convert to studly caps*/
    for (; *word; ++word, ++i) {
        c = *word;
        if (!(i % 2) && c >= 'a' && c <= 'z')       /* even position uppercase */
            *word = toUpperCase(c);
        else if ((i % 2) && c >= 'A' && c <= 'Z')   /* odd position lowercase */
            *word = toLowerCase(c);
    }

}

int main(){
    char str[100];

    /*Read word from the keyboard using scanf*/
    //printf("Enter a word: ");
    scanf("%s", str);
    
    /*Call studly*/
    studly(str);
    
    /*Print the new word*/
    printf("%s\n", str);
    
    return 0;
}
