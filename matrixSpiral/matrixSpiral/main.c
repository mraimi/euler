//
//  main.c
//  matrixSpiral
//
//  Created by Michael Raimi on 1/19/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <stdio.h>


// only works with nxn array
int [][] fill(int array[][], int length){
    int i,j,k=1;
    for(i=0;i<length-1;i++){
        for (j=0;j<length-1;j++){
            array[i][j]=k++;
        }
    }
    return array;
}

int main(int argc, const char * argv[])
{


    
    return 0;
}

