/* Name: Makenzie Brian
 * Date: Januray 31, 2016
 * Filename: linkedList.c
 */

#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {
	lst -> firstLink = malloc(sizeof(struct DLink));
	assert(lst -> firstLink != 0);
	lst -> lastLink = malloc(sizeof(struct DLink));
	assert(lst -> lastLink != 0);
	
	lst -> firstLink -> next = lst -> lastLink;
	lst -> lastLink -> prev = lst -> firstLink;
	lst -> size = 0;
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}


/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
	struct DLink *newLink = malloc(sizeof(struct DLink));
	assert(newLink != 0);
	newLink -> value = v;
	newLink -> next = l;
	newLink -> prev = l -> prev;
	
	l -> prev -> next = newLink;
	l -> prev = newLink;

	lst -> size++;
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/
void _removeLink(struct linkedList *lst, struct DLink *l)
{
	assert(l != 0);
	l -> next -> prev = l -> prev;
	l -> prev -> next = l -> next;
	free(l);
	
	lst -> size--;
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/
int isEmptyList(struct linkedList *lst) 
{
	return(lst -> size == 0);
}

/* De-allocate all links of the list

	param: 	lst		pointer to the linked list
	pre:	none
	post:	All links (including the two sentinels) are de-allocated
*/
void freeLinkedList(struct linkedList *lst)
{
	while(!isEmptyList(lst)) {
		/* remove the link right after the first sentinel */
		_removeLink(lst, lst->firstLink->next);
	}		
	/* remove the first and last sentinels */
	free(lst->firstLink);
	free(lst->lastLink);	
}

/* 	Deallocate all the links and the linked list itself. 

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	the memory used by v->data is freed
*/
void deleteLinkedList(struct linkedList *lst)
{
	assert (lst != 0);
	freeLinkedList(lst);
	free(lst);
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
	struct DLink *temp;
	printf("The list contains:");
	temp = lst -> firstLink;
	for(int i=0; i<lst->size; i++){
		temp = temp -> next;
		printf( " %d " , temp -> value);
	}

}

/* ************************************************************************
	Deque Interface Functions
************************************************************************ */

/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/
void addFrontList(struct linkedList *lst, TYPE e)
{
	_addLinkBefore(lst, lst -> firstLink -> next, e);	
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/
void addBackList(struct linkedList *lst, TYPE e) {
  
	_addLinkBefore(lst, lst -> lastLink, e);
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/
TYPE frontList (struct linkedList *lst) {
	return(lst -> firstLink -> next -> value);
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/
TYPE backList(struct linkedList *lst)
{
	return(lst -> lastLink -> prev -> value);
}



/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/
void removeFrontList(struct linkedList *lst) {
   	assert(!isEmptyList(lst));
	_removeLink(lst, lst -> firstLink -> next);

}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/
void removeBackList(struct linkedList *lst)
{	
	assert(!isEmptyList(lst));
	_removeLink(lst, lst -> lastLink -> prev);
	
}


/* ************************************************************************
	Stack Interface Functions
************************************************************************ */

/* 
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
	addFrontList(lst, v);

}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList(struct linkedList *lst, TYPE e) {
	int x = 0;
	struct DLink *temp;
	temp = lst -> firstLink;
	for(int i=0; i<lst->size; i++){
		temp = temp -> next;
		if(EQ(temp->value, e)){
			x = 1;
			break;
		}
	}
	return(x);
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {
	if(containsList(lst, e)){
		struct DLink *temp;
		temp = lst -> firstLink;
		for(int i=0; i<lst->size; i++){
			temp = temp -> next;
			if(EQ(temp->value, e)){
				_removeLink(lst, temp);
				break;
			}
		}
	}
	else{
		printf("This value is not caontained in the deque.");
	}
	
}