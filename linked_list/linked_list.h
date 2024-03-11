#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

#include "element.h"

typedef struct LinkedList LinkedList;

LinkedList* list_create();
void list_destroy(LinkedList* list);
void list_insertFirst(LinkedList* list, Element element);
void list_insertAfter(LinkedList* list, int pos, Element element);
bool list_removeFirst(LinkedList* list);
bool list_removeAt(LinkedList* list, int pos);
void list_print(LinkedList* list);

void list_printElements(LinkedList* l1, LinkedList* l2);
bool list_equals(LinkedList* l1, LinkedList* l2);
int list_isSorted(LinkedList* l); //Dois elementos igual no inicio dão errado
void list_removeDuplicates(LinkedList* l);//meh
void list_printReverse(LinkedList* l);
LinkedList* reverse(LinkedList* l);


#endif