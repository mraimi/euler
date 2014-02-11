//
//  main.c
//  largestPrime
//
//  Created by Michael Raimi on 1/25/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//
//  Tried to use sieve of eratosthenes but couldn't get it up and running
//  
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
//    long long n=13195;//600851475143;
/*    int memo[n];
    long long x;
    for (x=0; x<n; x++) {
        memo[x]=0;
    }
    
    long long i;
    for (i=2; i<n; i++) {
        long long counter=i, total=i;
        while (total<=n) {
            //printf("%lld\n",total);
            total += counter;
            //printf("cross off: %lld\n", total);
            if (total<=n) {
                memo[total]=1;
            }
            
            
        }
    }

    for (i=n-1; i>=2; i--) {
        // printf("%lldl\n",i);
        int b = memo[i];
        if (b<1 && n%i==0) {
            printf("%lldl\n",i);
            break;
        }
    } */
    
    
    long long div;
    long long num=600851475143;
    long long biggestDiv=0;
    
    while (num!=1) {
        for (div=2; div<=num; div++) {
            if(num%div==0){
                num = num/div;
                if (div>biggestDiv) {
                    biggestDiv = div;
                }
                break;
            }
                
        }
    }
    
    printf("%lld\n",biggestDiv);
    
    return 0;
}

