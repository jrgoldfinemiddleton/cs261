#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  char cmd = ' ';
  DynArr* mainList = createDynArr(10);

  printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
      /* clear the trailing newline character */
      while (getchar() != '\n');

      /* Fixme:  Your logic goes here! */

      /* see what the user's choice was */
      switch (cmd) {
          case 'l': {   /* load list from file of user's choosing */
                        FILE *in_file;
                        char filename[100];

                        printf("\nInput file: ");
                        scanf("%s", filename);

                        /* clear trailing chars */
                        while (getchar() != '\n');
                        printf("\n");
                        
                        /* try to open input file */
                        if ((in_file = fopen(filename, "r")) == 0)
                            fprintf(stderr, "Could not open %s\n", filename);
                        /* load the tasks and close the file */
                        else {
                            loadList(mainList, in_file);
                            fclose(in_file);
                        }

                        break;
                    }
          case 's': {   /* save list to file of user's choosing */
                        FILE *out_file;
                        char filename[100];

                        printf("\nOutput file: ");
                        scanf("%s", filename);

                        /* clear trailing chars */
                        while (getchar() != '\n');
                        printf("\n");

                        /* try to open output file */
                        if ((out_file = fopen(filename, "w")) == 0)
                            fprintf(stderr, "Could not open %s\n", filename);
                        /* save the tasks and close the file */
                        else {
                            saveList(mainList, out_file);
                            fclose(out_file);
                        }

                        break;
                    }
          case 'a': {   /* add a single new task to the list */
                        int priority;
                        char desc[TASK_DESC_SIZE];
                        TaskP newTask;

                        printf("\nEnter the priority: ");
                        scanf("%d", &priority);
                        while (getchar() != '\n');

                        printf("Enter a description for this task: ");
                        scanf("%[^\n]", desc);
                        while (getchar() != '\n');

                        /* create and add task to list */
                        newTask = createTask(priority, desc);
                        addHeap(mainList, newTask, compare);

                        printf("\nTask successfully added to the priority queue.\n");
                        break;
                    }
          case 'g': {   /* print the first task on the list */
                        TaskP firstTask;

                        /* get the root node's task and print it */
                        firstTask = getMinHeap(mainList);
                        printf("\nFirst ");
                        print_type(firstTask);
                        printf("\n");

                        break;
                    }
          case 'r': {   /* remove the first task from the list */
                        TaskP firstTask;

                        /* print the root node's task and delete it */
                        firstTask = getMinHeap(mainList);
                        removeMinHeap(mainList, compare);
                        printf("\nRemoving ");
                        print_type(firstTask);
                        printf("\n");

                        /* won't be needing it anymore */
                        free(firstTask);

                        break;
                    }
          case 'p': {   /* print out the list */
                        printf("\nTo-Do List:\n\n");
                        printList(mainList);

                        break;
                    }
          case 'e': 
                        break;
          default:      /* invalid selection */
                    printf("\nWhat?? That's not a choice!\n\n");
                    break;
      }


      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
  while(cmd != 'e');
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
