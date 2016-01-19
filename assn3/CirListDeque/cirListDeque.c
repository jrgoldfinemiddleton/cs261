#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX 


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q) 
{
  	/* FIXME: you must write this */
    assert(q != NULL);

    q->Sentinel = malloc(sizeof(struct DLink));
    assert(q->Sentinel != NULL);

    /* Make newly-initialized sentinel point to itself */
    q->Sentinel->value = TYPE_SENTINEL_VALUE;
    q->Sentinel->prev = q->Sentinel;
    q->Sentinel->next = q->Sentinel;

    q->size = 0;
    assert(q->size == 0);
}

/*
 create a new circular list deque
 
 */

struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	/* FIXME: you must write this */
    struct DLink *newLink = malloc(sizeof(struct DLink));
    assert(newLink != NULL);
    newLink->value = val;
    newLink->prev = NULL;
    newLink->next = NULL;

	/*temporary return value..you may need to change it*/
	return newLink;

}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
	/* FIXME: you must write this */

    assert(q != NULL);

    struct DLink *oldPrev;
    struct DLink *oldNext;
    struct DLink *newNode;

    oldPrev = q->Sentinel->next;

    /* iterate until finding lnk or sentinel*/
    while (oldPrev != lnk && oldPrev != q->Sentinel) {
        oldPrev = oldPrev->next;
    }

    /* check to see if precondition that lnk is in list holds */
    assert(oldPrev == lnk);

    oldNext = oldPrev->next;

    newNode = _createLink(v);
    newNode->prev = oldPrev;
    newNode->next = oldNext;
    oldPrev->next = newNode;
    oldNext->prev = newNode;
    ++(q->size);

    assert(lnk->next == newNode);
}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
	/* FIXME: you must write this */	 
    assert(q != NULL);

    _addLinkAfter(q, q->Sentinel->prev, val);

    assert(q->Sentinel->prev->value == val);
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	/* FIXME: you must write this */
    assert(q != NULL);

    _addLinkAfter(q, q->Sentinel, val);

    assert(q->Sentinel->next->value == val);
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
	/* FIXME: you must write this */

    assert(q != NULL);
    assert(q->size != 0);

	/*temporary return value..you may need to change it*/
	return q->Sentinel->next->value;
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */

    assert(q != NULL);
    assert(q->size != 0);

	/*temporary return value..you may need to change it*/
	return q->Sentinel->prev->value;
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	/* FIXME: you must write this */

    struct DLink *oldPrev;
    struct DLink *oldNext;

    assert(q != NULL);
    assert(q->size != 0);
    assert(lnk != NULL);

    oldPrev = lnk->prev;
    oldNext = lnk->next;

    free(lnk);
    lnk = NULL;

    --(q->size);

    oldPrev->next = oldNext;
    oldNext->prev = oldPrev;
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	/* FIXME: you must write this */
    assert(q != NULL);
    assert(q->size != 0);

    _removeLink(q, q->Sentinel->next);
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
  	/* FIXME: you must write this */
    assert(q != NULL);
    assert(q->size != 0);

    _removeLink(q, q->Sentinel->prev);
}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
    struct DLink *cur;

    if (q != NULL) {
        cur = q->Sentinel->next;

        while (cur != q->Sentinel && cur != NULL) {
            cur = cur->next;
            free(cur->prev);
            cur->prev = NULL;
        }

        if (cur == q->Sentinel)
            free(cur);
    }

    free(q);
    q = NULL;
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
  	/* FIXME: you must write this */

    assert(q != NULL);

	/*temporary return value..you may need to change it*/
	return q->size == 0;
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
    struct DLink *cur;
    assert(q != NULL);
    assert(q->size != 0);

    cur = q->Sentinel->next;

    while (cur != q->Sentinel) {
        printf("%g ", cur->value); /* WARNING: not portable to other types */
        cur = cur->next;
    }
    printf("\n\n");
}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
    struct DLink *cur;
    struct DLink *tmp;

    assert(q != NULL);
    assert(q->size != 0);

    cur = q->Sentinel;

    do {
        tmp = cur->next;
        cur->next = cur->prev;
        cur->prev = tmp;
        cur = tmp;
    } while (cur != q->Sentinel);
}
