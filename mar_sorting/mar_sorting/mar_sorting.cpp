//
//  mar_sorting.cpp
//  mar_sorting
//
//  Created by Michael Raimi on 3/1/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include "mar_sorting.h"




void exchange(std::vector<std::string>&V, int one, int two){
//done, checked
    
    std::string temp = V[one];
    V[one]=V[two];
    V[two]=temp;
}

int partition(std::vector<std::string> &V, int first, int last){
//done,checked
    
    int last_less=first-1, last_index = last, current;
    std::string pivot = V[last_index];
    //std::cout << "pivot is: " << pivot << std::endl;
    
    for (current=first; current<last; current++) {
        if(V[current] <= pivot){
            last_less++;
            exchange(V, current, last_less);
        }
    }
    
    exchange(V, last_less+1, last_index);
    

    return last_less+1;
}



void randomize(std::vector<std::string> &V){
    int size = (int)V.size();
    srand((int)time(NULL));
    int rando=rand();
    if(size==7){
        rando %= 6;
    } else {
       rando %=size;
    }
    
    exchange(V, size-1, rando);
    
    
}

int rand_partition(std::vector<std::string> &V, int first, int last){
    //done,checked
    randomize(V);
    
    int last_less=first-1, last_index = last, current;
    std::string pivot = V[last_index];
    //std::cout << "pivot is: " << pivot << std::endl;
    
    for (current=first; current<last; current++) {
        if(V[current] <= pivot){
            last_less++;
            exchange(V, current, last_less);
        }
    }
    
    exchange(V, last_less+1, last_index);
    
    
    return last_less+1;
}


