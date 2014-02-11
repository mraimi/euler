//
//  main.c
//  mergeLinkedList
//
//  Created by Michael Raimi on 1/21/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <stdio.h>
#include <time.h>       //for random number seed
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct List{
    struct Node *head;
};

void listInit(struct List* list){
    list->head=NULL;
}

void add(struct List *list, int value){
    struct Node* temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = value;
    temp->next=NULL;
    
    if (!list->head) {
        list->head=temp;
        
    } else {
        struct Node* helper=list->head;
        while (helper->next) {
            helper=helper->next;
        }
        helper->next=temp;
    }
    printf("%d added!\n", temp->data);
}

void printList(struct List* list){
    struct Node* temp = list->head;
    while (temp){
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf(" NULL\n");
}

int isEmpty(struct List *list){
    if (list->head) {
        return 0;
    } else {
        return 1;
    }
}

int *popHead(struct List *list){
    int *toReturn=NULL;
    
    if(isEmpty(list)){
        printf("underflow");
        return NULL;
    } else {
        struct Node *temp = list->head;
        *toReturn = temp->data;
        printf("%d", *toReturn);
        list->head=temp->next;
        free(temp);
        return toReturn;
    }
}
void destroy(struct List* list){
    while (!isEmpty(list)) {
       
        popHead(list);
    }
}

struct List *merge(struct List *list1, struct List *list2){
    struct List* result = (struct List*) malloc(sizeof(struct List));
    listInit(result);
    struct Node * t1 = list1->head;
    struct Node * t2 = list2->head;
    
    while (t1 && t2) {
        if (t1 < t2) {
            add(result, t1->data);
            t1 = t1->next;
        } else {
            add(result, t2->data);
            t2 = t2->next;
        }
    }
    
    return result;
}

int main(int argc, const char * argv[])
{

    struct List list1;
    struct List list2;
    listInit(&list1);
    listInit(&list2);
    srand((int)time(NULL));
    
    int i, randVal=rand()%10;

    for (i=0; i<10; i++) {
        add(&list1, randVal);
        randVal += rand()%10;
    }
    
    randVal = rand()%10;
    
    for (i=0; i<10; i++) {
        add(&list2, randVal);
        randVal += rand()%10;
    }
    
    printList(&list1);
    printList(&list2);
    
    struct List *result = merge(&list1, &list2);
    printList(result);
    //destroy(&list1);
    
    return 0;
}

