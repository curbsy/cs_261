/*  Name: Makenzie Brian
 *  Date: January 24, 2016
 *  File: calc.c
 */
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "dynamicArray.h"


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anything in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
		printf("in the end of else\n");
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	printf("add");
	double x = topDynArr(stack);
	popDynArr(stack);
	double y = topDynArr(stack);
	popDynArr(stack);
	
	pushDynArr(stack, x+y);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	double x = topDynArr(stack);
	popDynArr(stack);
	double y = topDynArr(stack);
	popDynArr(stack);
	
	pushDynArr(stack, y-x);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	double x = topDynArr(stack);
	popDynArr(stack);
	double y = topDynArr(stack);
	popDynArr(stack);
	
	pushDynArr(stack, y/x);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their multiplant is pushed back onto the stack.
*/
void multiply(struct DynArr *stack){
	double x = topDynArr(stack);
	popDynArr(stack);
	double y = topDynArr(stack);
	popDynArr(stack);
	
	pushDynArr(stack, y*x);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their value is pushed back onto the stack.
*/
void power(struct DynArr *stack){
	double x = topDynArr(stack);
	popDynArr(stack);
	double y = topDynArr(stack);
	popDynArr(stack);
	
	pushDynArr(stack, pow(y, x));
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top one element is popped and 
	the square is pushed back onto the stack.
*/
void square(struct DynArr *stack){
	double x = topDynArr(stack);
	popDynArr(stack);
	
	pushDynArr(stack, pow(x, 2.0));
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top one element is popped and 
	the cube is pushed back onto the stack.
*/
void cube(struct DynArr *stack){
	double x = topDynArr(stack);
	popDynArr(stack);
	
	pushDynArr(stack, pow(x, 3.0));	
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top one element is popped and 
	the abs val is pushed back onto the stack.
*/
void abso(struct DynArr *stack){
	double x = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, fabs(x));
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top one element is popped and 
	the square root is pushed back onto the stack.
*/
void sqrto(struct DynArr *stack){
	double x = topDynArr(stack);
	popDynArr(stack);
	
	pushDynArr(stack, pow(x, .50));	
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top one element is popped and 
	the number as th exponent to e is put back onto the stack.
*/
void expo(struct DynArr *stack){
	double x = topDynArr(stack);
	popDynArr(stack);
	
	pushDynArr(stack, pow(2.7182818, x));	
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top one element is popped and 
	the natural log is pushed back onto the stack.
*/
void ln(struct DynArr *stack){
	double x = topDynArr(stack);
	popDynArr(stack);
	
	pushDynArr(stack, log(x));		
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top one element is popped and 
	the log base 10 is pushed back onto the stack.
*/
void logo(struct DynArr* stack){
	double x = topDynArr(stack);
	popDynArr(stack);
	
	pushDynArr(stack, log10(x));		
}



double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;
	double *a;

	a  = malloc(sizeof(double));
	//set up the stack
	stack = createDynArr(20);
	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		printf("top for \n");
		s = inputString[i];
		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			multiply(stack);
		else if(strcmp(s, "^") == 0)
			power(stack);
		else if(strcmp(s, "^2") == 0)
			square(stack);
		else if(strcmp(s, "^3") == 0)
			cube(stack);
		else if(strcmp(s, "abs") == 0){
			abso(stack);}
		else if(strcmp(s, "sqrt") == 0)
			sqrto(stack);
		else if(strcmp(s, "exp") == 0)
			expo(stack);
		else if(strcmp(s, "ln") == 0)
			ln(stack);
		else if(strcmp(s, "log") == 0)
			logo(stack);
		else if(isNumber(s, a)){
			pushDynArr(stack, *a);
			printf("pushed %f", *a);
		}

		else if(!strcmp(s, "pi")){
			pushDynArr(stack, 3.14159265);
		}
		else if(!strcmp(s, "e")){
			pushDynArr(stack, 2.7182818);
		}
		else{
			printf("There is an invalid input. Exiting the loop.\n");

			exit(0);
		}	
			
		
	printf("loop\n");
			
	}	//end for 

	result = topDynArr(stack);
	popDynArr(stack);

	if(!isEmptyDynArr(stack)){
		printf("The stack is not empty after result. There is a problem.\n");
	}
	return result;
}

int main(int argc, char *argv[]) 
{
	double e;

	// assume each argument is contained in the argve if(strcmp(s, "e")){
	// array
	// argc-1 determines the number of operands + operators
	if (argc == 1){
		//return 0;
		printf("Wrong\n");	
	}
	else{	
		e=calculate(argc,argv);
	}
	printf("This is your result: %f \n",e);

	return 0;
}
