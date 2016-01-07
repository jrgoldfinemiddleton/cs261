/* CS261- Assignment 1 - Q.4*/
/* Name: Jason Goldfine-Middleton
 * Date: 01/04/16
 * Solution description: A program that sorts a list of students in ascending order
 *                       by score.
 */

#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
    int max;
    int i;
    struct student tmp;

     /*Sort the n students based on their score*/
     /* Remember, each student must be matched with their original score after sorting */
    for (--n; n >= 0; --n) {
        max = 0;

        /* find max score */
        for (i = 0; i <= n; ++i)
            if (students[max].score < students[i].score)
                max = i;

        /* swap student with max score with student at end of unsorted subinterval */
        if (max != n) {
            tmp = students[n];
            students[n] = students[max];
            students[max] = tmp;
        }
    }
}

int main(){
    int i;

    /*Declare an integer n and assign it a value.*/
    int n = 10;

    /*Allocate memory for n students using malloc.*/
    struct student* students = malloc(n * sizeof(struct student));

    /*Generate random IDs and scores for the n students, using rand().*/

    /*srand((unsigned int) time(0));*/

    for (i = 0; i != n; ++i) {
        students[i].id = rand() % 10;
        students[i].score = rand() % 101;
    }

    /*Print the contents of the array of n students.*/
    for (i = 0; i != n; ++i)
        printf("ID%d score%d\n", students[i].id, students[i].score);
    printf("\n");

    /*Pass this array along with n to the sort() function*/
    sort(students, n);

    /*Print the contents of the array of n students.*/
    for (i = 0; i != n; ++i)
        printf("ID%d score%d\n", students[i].id, students[i].score);
    printf("\n");

    return 0;
}
