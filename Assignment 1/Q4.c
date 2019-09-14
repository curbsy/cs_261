/* CS261- Assignment 1 - Q.4*/
/* Name: Makenzie Brian
 * Date: January 15, 2016
 * Solution description: sorts an array of students based on their scores
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     
     /* Remember, each student must be matched with their original score after sorting */
	 	 int i = 0;
	 while(1){
		  if(students[i].score > students[i+1].score){
			  struct student temp = students[i+1];
			  students[i+1] = students[i];
			  students[i] = temp;
			  i = 0;
		  }
		  else{
			  i++;
			  if(i == n-1){
				  break;
			  }
		  }
	 }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10;
	
    /*Allocate memory for n students using malloc.*/
	struct student* arr;
	arr = malloc(n*sizeof(struct student));
	
    /*Generate random IDs and scores for the n students, using rand().*/
     srand(time(NULL));
	 for(int i=0; i<10; i++){
		 arr[i].id = rand()%10+1;
		 arr[i].score = rand()%101;
	 }
	 
    /*Print the contents of the array of n students.*/
	printf("The contents are: ");	
    for(int i=0; i<n; i++){
		 printf("%d  %d\n", arr[i].id, arr[i].score);
	 }
	 
    /*Pass this array along with n to the sort() function*/
    sort(arr, n);
	
    /*Print the contents of the array of n students.*/
    printf("The contents are: ");	
    for(int i=0; i<n; i++){
		 printf("%d  %d\n ", arr[i].id, arr[i].score);
	}
    return 0;
}
