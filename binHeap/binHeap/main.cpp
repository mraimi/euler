//
//  main.cpp
//  binHeap
//
//  Created by Michael Raimi on 1/29/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//
//  No child has a key less than its parents' key

#include <iostream>
#include <string>
#include <vector>



class bhNode{
    public:
        bhNode(): value(""), key(-1){}
        bhNode(int k, std::string *v): key(k), value(*v){}
    
    private:
        int key;
        std::string value;
    
};

class maxHeap{
    public:
        maxHeap(): max(), vect(){}
    
    private:
    std::vector<bhNode> vect;
    bhNode *max;
};
int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

