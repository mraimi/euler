//
//  main.c
//  CCI_Questions
//
//  Created by Michael Raimi on 12/23/13.
//  Copyright (c) 2013 Michael Raimi. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void reverse(char *toReverse){
    int count=0;
    count = (int)strlen(toReverse)/2;
    int i;
    for(i=0;i<=count;i++){
        //charSwap(i, toReverse);
        printf("%d\n",i);
        char temp = toReverse[i];
        toReverse[i]=toReverse[(strlen(toReverse)-1)-i];
        toReverse[strlen(toReverse)-1]=temp;
    }
    //printf("count: %d\n", count);
}

//void charSwap(int index, char *origStr){
//    char temp = origStr[index];
//    origStr[index]=origStr[(strlen(origStr)-1)-index];
//    origStr[strlen(origStr)-1]=temp;
//    
//}

int main(int argc, const char * argv[])
{

    char *toSend = "Laakmann McDowell";
    printf("before: %s\n", toSend);
    reverse(toSend);
    printf("after: %s\n", toSend);
    
    

}

