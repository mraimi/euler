//
//  main.cpp
//  CCI_linkedLists
//
//  Created by Michael Raimi on 1/25/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <iostream>
#include <list>
#include <stdlib.h>
#include <time.h>
#include <set>




using namespace std;

class myNode{
    public:
    myNode(): data(NULL){}
    myNode(int i): data(i){}
    myNode getHead(void)
    private:
        int data;
        struct myNode *next;
};

class myList {
    public:
        myList(): head(NULL){}
    private:
        myNode *head;
};

void printInt(std::list<int> toPrint){
    
    for (list<int>::iterator iter = toPrint.begin(); iter!= toPrint.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << "\n";
}

void addFront(class myList *ml, int toAdd){
    myNode *temp = new myNode(toAdd);
    
    if (!ml->head) {
        ml->head=temp;
    }
}

std::list<int> removeDupesNaive(std::list<int> l){
    for (list<int>::iterator iter1 = l.begin(); iter1!=l.end(); ++iter1) {
        for (list<int>::iterator iter2 = iter1; iter2!=l.end(); ++iter2) {
            ++iter2;
            if (*iter1 == *iter2) {
                l.erase(iter2);
            }
        }
    }
    return l;
}

std::list<int> removeDupesSet(std::list<int> l){
    std::list<int> toReturn;
    
    std::set<int> intSet;
    for (list<int>::iterator iter = l.begin(); iter!=l.end(); ++iter) {
        intSet.insert(*iter);
    }
    for (set<int>::iterator iter = intSet.begin(); iter!=intSet.end(); ++iter) {
        toReturn.push_front(*iter);
    }
    
    return toReturn;
}

int main(int argc, const char * argv[])
{
    //srand((int)time(NULL));
    std::list<int> duplicates;
    
    for (int i=0; i<10; i++) {
        duplicates.push_back(i);
        duplicates.push_back(i);
    }
    
    cout << "before: ";
    printInt(duplicates);
    cout << "after removeDupesNaive:";
    printInt(removeDupesNaive(duplicates));
    
    cout << "\nbefore: ";
    printInt(duplicates);
    cout << "after removeDupesSet:";
    printInt(removeDupesSet(duplicates));
    
    
    
    
    
    
    
    return 0;
}

