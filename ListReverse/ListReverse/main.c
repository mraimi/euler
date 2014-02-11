//
//  main.c
//  ListReverse
//
//  Created by Michael Raimi on 1/17/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node* stackPointer = NULL;
struct Node *head=NULL;

struct Node{
    int data;
    struct Node* next;
};

struct Node * reverse(struct Node *head){
    struct Node *temp = head->next;
    struct Node *temp2 = temp->next;
    head->next=NULL;
    
    while(temp2){
        temp->next=head;
        head=temp;
    
        temp=temp2;
        temp2=temp2->next;
    }
    
    temp->next =head;
    head=temp;
    return head;
}

void printList(struct Node *head){
    struct Node *temp=head;
    while(temp){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    printf("_____________________________\n\n");
}

void push(struct Node* head, int x){
    
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data=x;
    
    if(!stackPointer){
        stackPointer = temp;
    } else {
        stackPointer->next = temp;
        stackPointer = temp;
    }
}

struct Node* pop(){
    int count=0,i;
    struct Node* temp = NULL;
    
    if(head){
        temp = head;
    } else {
        printf("underflow");
        return temp;
    }
    
    while (temp->next) {
        count++;
        temp = temp->next;
    }
    
    temp=head;
    
    for (i=0; i<count-1; i++) {
        temp = temp->next;
    }
    
    struct Node* toReturn;
    toReturn = temp->next;
    temp->next = NULL;
    
    return toReturn;
}



int main(int argc, const char * argv[])
{
    struct Node a = {5, 0};
    struct Node b = {4, &a};
    struct Node c = {3, &b};
    struct Node d = {2, &c};
    struct Node e = {1, &d};
    
    head=&e;
    
    printList(head);
    head = reverse(head);
    printList(head);
    
    struct Node* toPrint = pop();
    printf("pop: %d\n", toPrint->data);
    //free(&*toPrint);
    toPrint = pop();
    printf("pop: %d\n", toPrint->data);
    //free(&toPrint);
    push(head, 109);
    toPrint = pop();
    printf("pop: %d\n", toPrint->data);
    

    return 0;
}

