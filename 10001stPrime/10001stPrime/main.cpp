//
//  main.cpp
//  10001stPrime
//
//  Created by Michael Raimi on 1/28/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//
//  Using a bool vector a la sieve of eratosthenes

#include <iostream>
#include <vector>

//works in batches, base is for recursion
void nth_prime(unsigned int runningCount, unsigned int base, unsigned int *primeCount, std::vector<bool> *bv){
    
    if (base==0){
        bv->at(0)=false;
        bv->at(1)=false;
        runningCount=1;
    } else {
        //runningCount=base;
    }
    
    for (std::vector<bool>::iterator iter = bv->begin(); iter!=bv->end(); ++iter) {
        int i=2, multiple=i+i;
        
        if (*iter) {
            if (*primeCount==10000){
                int distance = (int) std::distance(bv->begin(), std::find(bv->begin(), bv->end(), bv));
                printf("%d\n", distance);
                return;
                
            }
            *primeCount = *primeCount +1;
            int test = bv->capacity();
            while ((multiple+i)<bv->capacity()) {
                multiple += i;
                bv->at(multiple) = false;
            
            }
        }
        runningCount++;
        i++;
    }
    
    nth_prime(runningCount, (int)bv->capacity()+10000, primeCount, bv);
}

int main(int argc, const char * argv[])
{
    unsigned int primeCount=0;
    
    std::vector<bool> bool_vec (10000,true);
    nth_prime(10000, 2 , &primeCount, &bool_vec);

    
    
    
    return 0;
}

