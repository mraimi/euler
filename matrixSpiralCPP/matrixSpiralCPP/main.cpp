//
//  main.cpp
//  matrixSpiralCPP
//
//  Created by Michael Raimi on 1/26/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <iostream>



void printShell(int mat[][5], int height, int length){
    
    printf("%d\n",mat[0][0]);
    
}


int main(int argc, const char * argv[])
{

    int mat[5][5] = {{1, 2, 3, 4, 5},
                    { 6, 7, 8, 9,10},
                    {11,12,13,14,15},
                    {16,17,18,19,20},
                    {21,22,23,24,25}};

    printShell(mat,5,5);
        return 0;
}

