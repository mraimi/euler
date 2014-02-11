//
//  main.cpp
//  factorialDigitSum
//
//  Created by Michael Raimi on 2/9/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

void digitSum(){
    

}

std::string factorial(int limit){
    
    char s[10000];
    sprintf(s, "%d", limit);
    
    std::string str(s);
    
    int carry=0, current = limit-1;
    
    while (limit>1) {
        //prev=limit;
        while (current) {

            for (std::string::reverse_iterator iter=str.rbegin(); iter!=str.rend(); iter++) {
                char c = *iter;
                int fromString = atoi(&c);
                int toWrite;
                    toWrite=((((current%10)*fromString)+carry)%10);
                char tw = '0'+toWrite;
                *iter = tw;
                carry = (current%10)*fromString-toWrite;
            }
            
            current /= 10;
            limit--;
        }
    }
    return str;
    
}




int main(int argc, const char * argv[])
{

    factorial(100);
    return 0;
}

