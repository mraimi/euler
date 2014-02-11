//
//  main.cpp
//  doMembersSumToN?
//
//  Created by Michael Raimi on 2/9/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>



int main(int argc, const char * argv[])
{
    
    std::set<int> numSet;
    srand((int)time(NULL));
    int target = rand()%100;
    int arr[50];
    for (int i=0; i<50; i++) {
        arr[i] = (int)rand()%100;
    }
    
    for (int i=0; i<50; i++) {
        if(numSet.find(target-arr[i])==numSet.end()){
            numSet.emplace(arr[i]);
        } else {
            printf("%d + %d = %d\n", arr[i], target-arr[i], target);
        }
    }
    
    
    
    
    return 0;
}

