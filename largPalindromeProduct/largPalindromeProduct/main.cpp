//
//  main.cpp
//  largPalindromeProduct
//
//  Created by Michael Raimi on 1/27/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;
    


int palinTest(char *s){
    int i;
    stack<char> stk;
    char c;
    
    int length = (int)strlen(s);
    
    for (i=0; i<length/2; i++) {
        c = *s;
        stk.push(*s);
        ++s;
    }
    
    if (length%2!=0) {
        s++;
    }
    
    while (*s) {
        char temp = stk.top();
        c = *s;
        if (c!=temp) {
            return 0;
        }
        stk.pop();
        s++;
    }
    
    return 1;
    
}

int main(int argc, const char * argv[])
{
    
    int outer, inner;
    int highest=-1;
    
    for (outer=999; outer>99; --outer) {
        for (inner=999; inner>99; --inner) {
            char test[33];
            sprintf(test, "%d", outer*inner);
            //cout << test << "\n";
            if (palinTest(test)){
                if(outer*inner>highest){
                    highest=outer*inner;
                    //cout << highest << "\n";
                }
            }
            
        }
       
    }
    printf("%d\n",highest);
    return 0;
}

