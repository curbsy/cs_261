#include "cirListDeque.h"
#include <stdio.h>
#include <stdlib.h>


void aT(int pred, char *mes){
   printf("%s: ", mes);
   if (pred)
      printf("PASSED\n");
   else
      printf("FAILED\n");
}



int main(int argc, char* argv[]) {
        
 struct cirListDeque *list;

   list = createCirListDeque();

   printf("\n\nTesting isEmptyCirListDeque, nothing is added yet...\n");
   aT(isEmptyCirListDeque(list), "Testing if the list is empty");

   printf("\n\nTesting addBackCirListDeque and backCirListDeque...\n");
   addBackCirListDeque(list, 5);
   printf("Adding 5 to back, calling backCirListDeque:");
   aT(EQ(backCirListDeque(list), 5), "Testing last element == 5");
   addBackCirListDeque(list, 12);
   aT(EQ(backCirListDeque(list), 12), "Testing last element == 12");
   addBackCirListDeque(list, 21);
   aT(EQ(backCirListDeque(list), 21), "Testing last element == 21");

   printf("Using printCirListDeque: \n");
   printCirListDeque(list);


   printf("\n\nTesting addFrontCirListDeque and frontListCirListDeque...\n");
   addFrontCirListDeque(list, 4);
   aT(EQ(frontCirListDeque(list), 4), "Testing first element == 4");
   addFrontCirListDeque(list, 10);
   aT(EQ(frontCirListDeque(list), 10), "Testing first element == 10");
   addFrontCirListDeque(list, 14);
   aT(EQ(frontCirListDeque(list), 14), "Testing first element == 14");

   printf("Using printCirListDeque: \n");
   printCirListDeque(list);

   printf("\n\nTesting removeFrontCirListDeque...\n");
   removeFrontCirListDeque(list);
   aT(EQ(frontCirListDeque(list), 10), "Testing first element == 10");
   removeFrontCirListDeque(list);
   aT(EQ(frontCirListDeque(list), 4), "Testing first element == 4");

   printf("Using printCirListDeque: \n");
   printCirListDeque(list);

   printf("\n\nTesting removeBackCirListDeque...\n");
   removeBackCirListDeque(list);
   aT(EQ(backCirListDeque(list), 12), "Testing last element == 12");
   removeBackCirListDeque(list);
   aT(EQ(backCirListDeque(list), 5), "Testing last element == 5");

   printf("Using printCirListDeque: \n");
   printCirListDeque(list);

   printf("\n\nTesting isEmpty again, this time it should not be empty...\n");
	aT(!isEmptyCirListDeque(list), "The list still contains some elements");


   printf("\n\nTesting reverseCirListDeque...\n");
   reverseCirListDeque(list);
   aT(EQ(frontCirListDeque(list), 5), "Testing last element == 5");
   aT(EQ(backCirListDeque(list), 4), "Testing last element == 4");



   printf("\n\nTesting deleteLinkedList... TESTING NOW COMPLETE\n");
   deleteCirListDeque(list);

	return 0;
}


