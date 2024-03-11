#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    Element element;
    struct Node* next;
} Node;

struct LinkedList {
    Node* head;
    int size;
};

LinkedList* list_create() {
    LinkedList* list = malloc(sizeof(LinkedList));

    list->head = NULL;
    list->size = 0;

    return list;
}

void list_destroy(LinkedList* list) {
    Node* cur = list->head;

    while (cur != NULL) {
        Node* trash = cur;

        cur = cur->next;
        free(trash);
    }
    free(list);
}

void list_insertFirst(LinkedList* list, Element element) {
    Node* newNode = malloc(sizeof(Node));

    newNode->element = element;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void list_insertAfter(LinkedList* list, int pos, Element element) {
    if (list->head == NULL || pos < 0) {
        list_insertFirst(list, element);
    } else {
        Node* cur = list->head;
        int i = 0;

        while (i < pos && cur->next != NULL) {
            cur = cur->next;
            i++;
        }

        Node* newNode = malloc(sizeof(Node));

        newNode->element = element;
        newNode->next = cur->next;
        cur->next = newNode;
        list->size++;
    }    
}

void list_print(LinkedList* list) {
    Node* cur = list->head;

    while (cur != NULL) {
        element_print(cur->element);
        cur = cur->next;
        if (cur != NULL) {
            printf(" -> ");
        }        
    }
    printf("\n");
}

bool list_removeFirst(LinkedList* list) {
    if (list->head == NULL) {
        return false;
    }

    Node* trash = list->head;

    list->head = list->head->next;
    free(trash);
    list->size--;

    return true;
}

bool list_removeAt(LinkedList* list, int pos) {
    // caso 0: posicao invalida
    if (pos < 0 || pos >= list->size) {
        return false;
    }

    // caso 1: lista vazia
    if (list == NULL) {
        return false;
    }

    // caso 2: remocao na cabeca
    if (pos == 0) {
        return list_removeFirst(list);
    } else { // caso 3: remocao na cauda
        Node* prev = list->head;
        int i = 0;

        while (i < pos - 1) {
            prev = prev->next;
            i++;
        }

        Node* trash = prev->next;

        prev->next = prev->next->next;
        free(trash);  
        list->size--;

    }

    return true;    
}

//EXERCICIOS

void list_printElements(LinkedList* l1, LinkedList* l2){
    Node* cur1 = l1->head;
    Node* cur2 = l2->head;
    int i;

    while (cur2 != NULL)
    {
        cur1= l1->head;
        i = 0;

        if(cur2->element > l1->size){
            printf("Elemento invalido");
        }
        else{
            while(i < (cur2->element)){
                i++;
                cur1 = cur1->next;
            }
            element_print(cur1->element);
            printf(" ");
        }

        cur2 = cur2->next;
    }
    
}

bool list_equals(LinkedList* l1, LinkedList* l2){
    Node* cur1 = l1->head;
    Node* cur2 = l2->head;
    int igual = 0;

    if(l1->size == l2->size){
        while(cur1 != NULL){
            if(cur1->element == cur2->element){
                igual++;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        if(igual ==  l1->size){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}


int list_isSorted(LinkedList* l){
    if (l == NULL || l->size < 2) {
        return 0; 
    }

    Node* cur = l->head;
    bool ordem;

    if(cur->element < cur->next->element){
        ordem = true;//Crescente 1
    }
    else if(cur->element > cur->next->element){
        ordem = false;//Decrescente 2
    }

    while (cur->next != NULL) {
        if (ordem == true && cur->element > cur->next->element) {
            return 0;
        } 
        else if (ordem == false && cur->element < cur->next->element) {
            return 0;
        }
        cur = cur->next;
    }

    if(ordem == true){
        return 1;
    }
    else{
        return 2;
    }
}

void list_removeDuplicates(LinkedList* l){
Node* cur = l->head;
Node* prev = NULL;

while (cur != NULL) {
    Node* temp = l->head;
    bool isDuplicate = false;

    while (temp != cur) {
        if (temp->element == cur->element) {
            isDuplicate = true;
            break;
        }
        temp = temp->next;
    }

    if (isDuplicate) {
        Node* nextNode = cur->next;
        if (prev != NULL) {
            prev->next = nextNode;
        } else {
            l->head = nextNode;
        }
        free(cur);
        cur = nextNode;
    } else {
        prev = cur;
        cur = cur->next;
    }
}

list_print(l);

}

void list_printReverse(LinkedList* l){  
    Node* cur = l->head;
    int NovaLista[l->size];
    int i = 0;

    while (cur != NULL)
    {
        NovaLista[i] = cur->element;
        i++;
        cur = cur->next;
    }

    for (int i = l->size-1; i >= 0; i--)
    {
        printf("%d ", NovaLista[i]);
    }

}

LinkedList* reverse(LinkedList* l){
    Node* cur = l->head;
    int NovaLista[l->size];
    int i = 0;

    while (cur != NULL)
    {
        NovaLista[i] = cur->element;
        i++;
        cur = cur->next;
    }

    LinkedList* ReverseList = list_create();

    for (int i = 0; i < l->size; i++)
    {
        list_insertFirst(ReverseList, NovaLista[i]); 
    }

    list_print(ReverseList);

}





