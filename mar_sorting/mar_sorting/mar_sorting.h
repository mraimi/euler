//
//  mar_sorting.h
//  mar_sorting
//
//  Created by Michael Raimi on 3/1/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#ifndef __mar_sorting__mar_sorting__
#define __mar_sorting__mar_sorting__

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

/*
 
 
 Quicksort is a divide and conquer algorithm that typically
 operates at O(n*log(n)) with a rare quadratic wost case.
 
 
 */

void exchange(std::vector<std::string>&V, int current, int last_less);
void randomize(std::vector<std::string> &V);
int partition(std::vector<std::string> &V, int first, int last);
int rand_partition(std::vector<std::string> &V, int first, int last);





std::vector<std::string> quick_sort(std::vector<std::string> &A, int first, int last);



#endif /* defined(__mar_sorting__mar_sorting__) */
