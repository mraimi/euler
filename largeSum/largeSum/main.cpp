//
//  main.cpp
//  largeSum
//
//  Created by Michael Raimi on 2/6/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

void largeSum(int firstNDigits, std::vector<string> *sv){
    string result("");
    int carry=0;
    
    
    for (int i =1; i<=firstNDigits; i++) {
        int digitTotal=0;
        string curr;
        int value;
        
        for (std::vector<string>::iterator iter=sv->begin(); iter!=sv->end(); iter++) {
            curr = *iter;
            value = curr.at(curr.length()-i) - '0';
            digitTotal += value;
        }
        
        digitTotal+=carry;
        char toAdd = '0'+ digitTotal%10;
        result.insert(result.begin(), toAdd);
        carry = digitTotal/10;
    }
    cout << carry;
    cout << result << "\n";
}






int main(int argc, const char * argv[])
{
    
    
    vector<string> *sv = new vector<string>();
    ifstream fs("largeSum.txt");
    while (fs.is_open()) {
        
        string s;
        getline(fs,s);
        if (s.length()==0) {
            break;
        }
        
        sv->push_back(s);
    }
    
    largeSum(50,sv);
    return 0;
}

