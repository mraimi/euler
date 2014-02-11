//
//  main.c
//  mult3_5_under1000
//
//  Created by Michael Raimi on 1/25/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//
//  Better solution offers 40% less operations than the naive solution

#include <stdio.h>


int naive(int n, int j, int limit){
    int operations=0;
    
    int i, total=0;
    for (i=0;i<limit;i++) {
        if(i%n==0 || i%j==0){
            total += i;
        }
        operations++;
    }
    printf("naive operations: %d\n",operations );
    return total;
}

int better(int n, int j, int limit){
    int operations=0;
    int total=0, x = n, y = j, z=n*j;
    
    while(x<limit){
        total += x;
        x += n;
        operations++;
    }
    
    while(y<limit){
        total += y;
        y += j;
        operations++;
    }
    
    while(z <limit){
        total -= z;
         z += n*j;
        operations++;
        
    }
    printf("better operations: %d\n",operations );
    return total;
}

int main(int argc, const char * argv[])
{
    int naiveTotal = naive(3,5, 1000000000);
    printf("naive total: %d\n", naiveTotal);
    
    int betterTotal = better(3, 5, 1000000000);
    printf("better total: %d\n", betterTotal);
    
    return 0;
}

