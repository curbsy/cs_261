/* CS261- Assignment 1 - Q.5*/
/* Name: Makenzie Brian
 * Date: January 15, 2016
 * Solution description: Converts a word to studly caps
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void studly(char* word){
     /*Convert to studly caps*/
	 int i=0;
	 while(word[i]){
		 if(i%2 == 0){  //even
			 putchar(toupper(word[i]));
			 i++;
		 }
		 else{
			 putchar(tolower(word[i]));
			 i++;
		 }
	 }
}

int main(){
    /*Read word from the keyboard using scanf*/
	char thing[100];
	printf("Enter word:");
    scanf("%s", thing);
	
    /*Call studly*/
	printf("The new word is:");
	studly(thing);    
	printf("\n");

    return 0;
}
