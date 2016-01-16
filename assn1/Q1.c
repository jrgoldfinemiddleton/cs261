/* CS261- Assignment 1 - Q.1*/
/* Name: Jason Goldfine-Middleton
 * Date: 01/04/16
 * Solution description: A program that allocates memory for an array of structures
 *                       and prints the contents before deallocating the memory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int NUM_STUDENTS = 10;

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* students = malloc(NUM_STUDENTS * sizeof(struct student));

     /*return the pointer*/
     return students;
}

void generate(struct student* students){
    int tmpScr;
    int tmpId;
    int swapIndex;
    int i;

    /*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/

    /* Allocate IDs in order and determine scores */
    for (i = 0; i != NUM_STUDENTS; ++i) {
        students[i].id = i + 1;
        students[i].score = rand() % 101;
    }

    /* Shuffle the students around */
    for (i = 0; i != NUM_STUDENTS; ++i) {
        swapIndex = rand() % (i + 1);

        /* Swap the student at index i with student at
           position swapIndex */
        tmpId = students[i].id;
        tmpScr = students[i].score;
        students[i].id = students[swapIndex].id;
        students[i].score = students[swapIndex].score;
        students[swapIndex].id = tmpId;
        students[swapIndex].score = tmpScr;
    }
}

void output(struct student* students){
    int i;

     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    for (i = 0; i != NUM_STUDENTS; ++i)
        printf("ID%d score%d\n", students[i].id, students[i].score);
    printf("\n");

}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int min = 100;
     int max = 0;
     int total = 0;
     int i;

     for (i = 0; i != NUM_STUDENTS; ++i) {
         if (students[i].score < min)
             min = students[i].score;

         if (students[i].score > max)
             max = students[i].score;

         total += students[i].score;
     }

     printf("%d\n", min);
     printf("%d\n", max);
     printf("%lf\n", total / (double) NUM_STUDENTS);
}

void deallocate(struct student* stud){
    /*Deallocate memory from stud*/
    if (stud) /* only deallocate if stud is not NULL */
        free(stud);
}

int main(){
    struct student* stud = NULL;

    /*seed rng
    srand((unsigned int) time(0)); */

    /*call allocate*/
    stud = allocate();

    /*call generate*/
    generate(stud);

    /*call output*/
    output(stud);

    /*call summary*/
    summary(stud);

    /*call deallocate*/
    deallocate(stud);

    return 0;
}
