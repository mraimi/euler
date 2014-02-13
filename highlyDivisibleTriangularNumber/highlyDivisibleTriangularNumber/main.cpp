//
//  main.cpp
//  highlyDivisibleTriangularNumber
//
//  Created by Michael Raimi on 2/13/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <iostream>
#include <cmath>



long getFactorCount(long n){
    long factCount=0;
    bool square=false;
    
   
    
    
    for (int i=1; i<=(int)sqrt(n); i++) {
        if (n%i==0) {
            factCount++;
        }
        if(i*i==n){
            square=true;
        }
    }
    if(square){
        return factCount*2-1;
    }
    return factCount*2;
}


void findHDTN(int factorMin){
    long base=1;
    long count = 1;
    
    
    while (getFactorCount(base)<500) {
        ++count;
        base+=(count);
        
    }
    std::cout << base << std::endl;
}


int main(int argc, const char * argv[])
{
    findHDTN(500);
        return 0;
}

