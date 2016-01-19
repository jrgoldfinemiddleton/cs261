#include "linkedList.h"
#include <stdio.h>

void _printList(struct linkedList *lst);

int main(){
    struct linkedList* q = createLinkedList();
    addBackList(q, (TYPE)1);
    addBackList(q, (TYPE)2);
    addBackList(q, (TYPE)3);
    addFrontList(q, (TYPE)4);
    addFrontList(q, (TYPE)5);
    addFrontList(q, (TYPE)6);
    _printList(q);
    printf("%d\n", frontList(q));
    printf("%d\n", backList(q));
    removeFrontList(q);
    removeBackList(q);
    _printList(q);
    return 0;
}
