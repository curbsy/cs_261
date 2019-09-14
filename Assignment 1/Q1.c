/* CS261- Assignment 1 - Q.1*/
/* Name: Makenzie Brian
 * Date: January 15, 2016
 * Solution description: creates array of students, gives information, deallocates memory when done
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* students;
     students =  malloc(10*sizeof(struct student));
	 
     /*return the pointer*/
	 return students;
}

void generate(struct student* students){
     /*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
     srand(time(NULL));
	 int i;
	 for( i=0; i<10; i++){
		 students[i].id = rand()%10+1;
		 students[i].score = rand()%101;
	 }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	 int i;
	 for(i=0; i<10; i++){
		 printf("%d  %d\n", students[i].id, students[i].score);
	 }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int minimum = students[0].score; 
	int i;
	 for(i=0; i<10; i++){
		  if(minimum>students[i].score){
			   minimum = students[i].score;
		  }
	 }
	 
	 int maximum = students[0].score;
	 for(i=0; i<10; i++){
		 if(maximum<students[i].score){
			 maximum = students[i].score;
		 }
	 }
	 
	 float average = 0;
	 for(i=0; i<10; i++){
		  average += students[i].score;
	 }
	 average = average/10.0;
	 
	 printf("The minimum is %d\n", minimum);
	 printf("The maximum is %d\n", maximum);
	 printf("The average is %f\n", average);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	 free(stud);
}

int main(){
    struct student* stud = NULL;
    
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
