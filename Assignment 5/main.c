#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  char cmd = ' ';
  DynArr* mainList = createDynArr(10);
  int pri;
  char desc[TASK_DESC_SIZE];
  TYPE task;
  FILE *fp;


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
	  if(cmd == 'l'){
		  fp = fopen("todo.txt","r");
		  loadList(mainList,fp);
		  assert(fp != 0);
		  fclose(fp);
		  printf("File uploaded\n\n");
	  }
	  if(cmd == 's'){
		 fp = fopen("todo.txt","w");
		 saveList(mainList, fp);
		 fclose(fp);
		 printf("File saved\n\n");
      }

      if(cmd == 'a'){
		 printf("Enter task priority as a number(0-999): ");
		 scanf("%d", &pri);
		 printf("\nEnter a task description: ");
		 /*for(i=0;i<TASK_DESC_SIZE; i++){
			desc[i] = getchar();
		 }*/
		 scanf("\t%[^\n]", desc);
		 task = createTask(pri, desc);
		 addHeap(mainList, task, compare);
		 printf("\nNew task has been added\n\n");
      }

      if(cmd == 'g'){
		 task = getMinHeap(mainList);
		 print_type(task);
      }

      if(cmd == 'r'){
		removeMinHeap(mainList, compare);
		printf("Highest priority task has been removed\n\n");
      }


      if(cmd == 'p'){
		printf("List is: \n");
		printList(mainList);
      }

      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
  while(cmd != 'e');
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
