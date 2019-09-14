/* CS261- Assignment 1 - Q.3*/
/* Name: Makenzie Brian
 * Date: January 15, 2016
 * Solution description: Sortss an array of 20 random ints
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
	 
	 int i = 0;
	 while(1){
		  if(number[i] > number[i+1]){
			  int temp = number[i+1];
			  number[i+1] = number[i];
			  number[i] = temp;
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
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
	
    /*Allocate memory for an array of n integers using malloc.*/
    int* arr = malloc(n*sizeof(int));
	
    /*Fill this array with random numbers between 0 and n, using rand().*/
     srand(time(NULL));
	for(int i=0; i<n; i++){
		 arr[i] = rand()%n;
	}
	
    /*Print the contents of the array.*/
	printf("The contents are: ");
	for(int i=0; i<n; i++){
		 printf("%d\n", arr[i]);
	}	 
    /*Pass this array along with n to the sort() function.*/
    sort(arr, n);
	
    /*Print the contents of the array.*/  
	printf("The contents are: ");	
    for(int i=0; i<n; i++){
		 printf("%d\n", arr[i]);
	}
    return 0;
}
