/* CS261- Assignment 1 - Q.2*/
/* Name: Makenzie Brian
 * Date: January 15, 2016
 * Solution description: passes values to function by reference and value, manipulates values and reprints values
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    (*a) = 2*(*a);
	
    /*Set b to half its original value*/
    (*b) = (*b)/2;
	
    /*Assign a+b to c*/
    c = (*a)+(*b);
	
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
    int x = 7;
	int y = 8;
	int z = 9;
	
    /*Print the values of x, y and z*/
    printf("The value of x is %d\n", x);
	printf("The value of y is %d\n", y);
	printf("The value of z is %d\n", z);
	
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int foop = foo(&x, &y, z);
	
    /*Print the value returned by foo*/
    printf("Foo returns %d\n", foop);
	
    /*Print the values of x, y and z again*/
	printf("The value of x is %d\n", x);
	printf("The value of y is %d\n", y);
	printf("The value of z is %d\n", z);
	
    /*Is the return value different than the value of z?  Why?*/
    return 0;
}
    
    
