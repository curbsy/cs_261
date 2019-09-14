#include "linkedList.h"
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
        
   struct linkedList *list;

   list = createLinkedList();

   printf("\n\nTesting isEmpty, nothing is added yet...\n");
   aT(isEmptyList(list), "Testing if the list is empty");

   printf("\n\nTesting addBack and backList...\n");
   addBackList(list, 5);
   printf("Adding 5 to back, calling backList:");
   aT(EQ(backList(list), 5), "Testing last element == 5");
   addBackList(list, 12);
   aT(EQ(backList(list), 12), "Testing last element == 12");
   addBackList(list, 21);
   aT(EQ(backList(list), 21), "Testing last element == 21");

   printf("Using printList: \n");
   _printList(list);


   printf("\n\nTesting addFront and frontList...\n");
   addFrontList(list, 4);
   aT(EQ(frontList(list), 4), "Testing first element == 4");
   addFrontList(list, 10);
   aT(EQ(frontList(list), 10), "Testing first element == 10");
   addFrontList(list, 14);
   aT(EQ(frontList(list), 14), "Testing first element == 14");

   printf("Using printList: \n");
   _printList(list);

   printf("\n\nTesting removeFront...\n");
   removeFrontList(list);
   aT(EQ(frontList(list), 10), "Testing first element == 10");
   removeFrontList(list);
   aT(EQ(frontList(list), 4), "Testing first element == 4");

   printf("Using printList: \n");
   _printList(list);

   printf("\n\nTesting removeBack...\n");
   removeBackList(list);
   aT(EQ(backList(list), 12), "Testing last element == 12");
   removeBackList(list);
   aT(EQ(backList(list), 5), "Testing last element == 5");

   printf("Using printList: \n");
   _printList(list);

   printf("\n\nTesting isEmpty again, this time it should not be empty...\n");
   aT(!isEmptyList(list), "The list still contains some elements");


   printf("\n\nTesting containsList...\n");
   aT(containsList(list, 5), "Checking that the list still contains 5");
   aT(containsList(list, 4), "Checking that the list still contains 4");


   printf("\n\nTesting addList...\n");
   addList(list, 8);
   aT(containsList(list, 8), "Checking that the list now contains 8");


   printf("Using printList: \n");
   _printList(list);


   printf("\n\nTesting removeList...\n");
   removeList(list, 4);
   aT(!containsList(list, 4), "Testing that 4 is no longer in the list");


   printf("Using printList: \n");
   _printList(list);


   printf("\n\nTesting deleteLinkedList... TESTING NOW COMPLETE\n");
   deleteLinkedList(list);

	return 0;
}


