//
//  main.cpp
//  mar_sorting
//
//  Created by Michael Raimi on 3/1/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <iostream>
#include "mar_sorting.h"

int main(int argc, const char * argv[])
{

    std::vector<std::string> sv = {"cat","rhino","doge","yellow","fada","zenith","mang"};
    int partition_index = rand_partition(sv, 0, (int)sv.size()-1);
    //exchange(sv, 0, 1);
    
    for (std::vector<std::string>::iterator iter = sv.begin(); iter!=sv.end(); iter++ ) {
        std::cout << *iter << std::endl;
    }
    
    std::cout << "partition index: " <<partition_index << std::endl;
    return 0;
}

