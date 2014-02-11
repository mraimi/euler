//
//  main.c
//  BinaryTree
//
//  Created by Michael Raimi on 1/21/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Tree {
    struct Node *root;
};


struct Node{
    struct Node *left;
    struct Node *right;
    int data;
};

struct Tree* treeInit(void){
    struct Tree *newTree = (struct Tree *) malloc(sizeof(struct Tree));
    newTree->root = NULL;
    
    return newTree;
}

void printInOrder(struct Node* n){
    
    if(n->left){
       // printf("going left\n");
        printInOrder(n->left);
    }
    printf("%d ",n->data);
    if(n->right){
     //   printf("going right\n");
        printInOrder(n->right);
    }
}


void add(struct Tree *tree, int newData){
    struct Node* temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = newData;
    temp->left = NULL;
    temp->right= NULL;
    
    if (!tree->root) {
        tree->root = temp;
    } else {
        struct Node *helper = tree->root;
        struct Node *helperParent;
        
        while (1) {
            helperParent = helper;
            if(newData<helper->data){
                helper = helper->left;
                if(!helper){
                    helperParent->left=temp;
                    return;
                }
            } else {
                helper = helper->right;
                if(!helper){
                    helperParent->right=temp;
                    return;
                }
            }
        }
    }
}


int main(int argc, const char * argv[])
{
    struct Tree *t = treeInit();
    int i;
    for (i=0; i<10; i++) {
        add(t, i);
    }
    printInOrder(t->root);
    printf("\n");
    
    
    return 0;
}

