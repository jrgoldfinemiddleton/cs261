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
    /* FIXME: you must write this */
    assert(lst != NULL);

    lst->firstLink = malloc(sizeof(struct DLink));
    lst->lastLink  = malloc(sizeof(struct DLink));

    lst->firstLink->prev = NULL;
    lst->firstLink->next = lst->lastLink;
    lst->lastLink->prev = lst->firstLink;
    lst->lastLink->next = NULL;

    lst->size = 0;
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
    /* FIXME: you must write this */
    struct DLink *oldPrev;
    struct DLink *oldNext;
    struct DLink *newNode;

    assert(lst != NULL);
    assert(l != NULL);

    newNode = malloc(sizeof(struct DLink));
    assert(newNode != NULL);
    newNode->value = v;

    oldNext = l;
    oldPrev = oldNext->prev;
    oldNext->prev = newNode;
    oldPrev->next = newNode;
    newNode->prev = oldPrev;
    newNode->next = oldNext;

    ++(lst->size);
    assert(lst->size != 0);
}


/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e)
{
    /* FIXME: you must write this */
    int size;

    assert(lst != NULL);
    size = lst->size;

    _addLinkBefore(lst, lst->firstLink->next, e);
    assert(lst->size != 0);
    assert(lst->size == ++size);
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(struct linkedList *lst, TYPE e) {
    /* FIXME: you must write this */
    int size;

    assert(lst != NULL);
    size = lst->size;

    _addLinkBefore(lst, lst->lastLink, e);
    assert(lst->size != 0);
    assert(lst->size == ++size);
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {
    /* FIXME: you must write this */
    assert(lst != NULL);
    assert(lst->size != 0);

    /*temporary return value...you may need to change this */
    return lst->firstLink->next->value;
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
    /* FIXME: you must write this */
    assert(lst != NULL);
    assert(lst->size != 0);

    /*temporary return value...you may need to change this */
    return lst->lastLink->prev->value;
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
    /* FIXME: you must write this */
    struct DLink *oldPrev;
    struct DLink *oldNext;

    assert(lst != NULL);
    assert(l != NULL);
	
    oldPrev = l->prev;
    oldNext = l->next;

    free(l);
    l = NULL;

    oldPrev->next = oldNext;
    oldNext->prev = oldPrev;

    --(lst->size);
}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {
    /* FIXME: you must write this */
    int size;

    assert(lst != NULL);
    assert(lst->size != 0);

    size = lst->size;

    _removeLink(lst, lst->firstLink->next);
    assert(lst->size == --size);
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
    /* FIXME: you must write this */
    int size;

    assert(lst != NULL);
    assert(lst->size != 0);

    size = lst->size;

    _removeLink(lst, lst->lastLink->prev);
    assert(lst->size == --size);
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
    /* FIXME: you must write this */
    assert(lst != NULL);

    /*temporary return value...you may need to change this */
    return lst->size == 0;
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
    /* FIXME: you must write this */
    struct DLink *cur;
    assert(lst != NULL);

    cur = lst->firstLink->next;

    while (cur != lst->lastLink) {
        printf("%d ", cur->value); /* WARNING: not portable to other types */
        cur = cur->next;
    }
    printf("\n");
}

/* 
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
    /* FIXME: you must write this */
    assert(lst != NULL);

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
int containsList (struct linkedList *lst, TYPE e) {
    /* FIXME: you must write this */
    struct DLink *cur;

    assert(lst != NULL);
    assert(lst->size != 0);

    cur = lst->firstLink->next;

    while (cur != lst->lastLink && cur->value != e)
        cur = cur->next;

    /*temporary return value...you may need to change this */
    return cur != lst->lastLink;
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
    /* FIXME: you must write this */
    struct DLink *cur;

    assert(lst != NULL);
    assert(lst->size != 0);

    cur = lst->firstLink->next;

    while (cur != lst->lastLink && cur->value != e)
        cur = cur->next;

    if (cur != lst->lastLink)
        _removeLink(lst, cur);
}
