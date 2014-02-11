//
//  main.cpp
//  sumOfPrimes
//
//  Created by Michael Raimi on 2/4/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[])
{
    long long total=0;
    int pCount=0;
    vector<bool>bv(1000002, true);
    bv.at(0)=false;
    bv.at(1)=false;
    for (int i=2; i<1000002; i++) {
        int mult=i;
        if (bv.at(i)) {
            pCount++;
            if(pCount==10001){
                cout << "10001st prime: " << i << "\n";
            }
            while (mult+i<1000002) {
                mult += i;
                bv.at(mult)=false;
            }
        }
    }
    
    for (int i=1000000; i>=2; i--) {
        if(bv.at(i)==true){
            cout << "largest prime: " << i;
            break;
        }
    }
    
    for (int i=2; i<2000000; i++) {
        if (bv.at(i)) {
            total += i;
        }
    }
    
    cout << total << "\n";
    cout << "prime count:" << pCount << "\n";
    return 0;
}

