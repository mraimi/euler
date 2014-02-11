//
//  main.c
//  evenFiboTotal
//
//  Created by Michael Raimi on 1/25/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int lib[4000000];

int memoFibo(int n){
    
    //base cases
    lib[0]=1;
    lib[1]=1;
    
    if(lib[n-1]<0){
        lib[n-1]=memoFibo(n-1);
    }
    return lib[n-1]+lib[n-2];
    
}

int naiveFiboSum(int limit){
    int prv=1, cur=2, sum=2, nxt;
    while (prv+cur<limit) {
        nxt = prv + cur;
        if(nxt%2==0){
            sum += nxt;
        }
        prv = cur;
        cur = nxt;
    }
    
    return sum;
}

int main(int argc, const char * argv[])
{
    
    
    int q;
    for(q=0;q<4000000;q++){
        lib[q]=-1;
    }
    
    while (1) {
        int i=1;
        char s[1001];
        sprint(s,itoa(memoFibo(i)));
        if(strlen(s)>=1000){
            printf("%d\n", i);
            break;
        }
    }

    printf("%d\n", naiveFiboSum(4000000));
    return 0;
}

