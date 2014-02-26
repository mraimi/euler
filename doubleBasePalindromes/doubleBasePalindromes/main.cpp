//
//  main.cpp
//  doubleBasePalindromes
//
//  Created by Michael Raimi on 2/25/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

bool pCheck(string s){
//done
    int limit=(int)(s.length())/2;
    for (int i=0; i<limit; i++) {
        if (s.at(i)!=s.at(s.length()-i-1)) {
            return false;
        }
    }
    return true;
}

int pow(int base, int exp){
//done
    int toReturn=base;
    if (exp==0) {
        return 1;
    } else if(exp==1){
        return base;
    }
    for (int i=1; i<exp; i++) {
        toReturn*=base;
    }
    return toReturn;
}

string dec2bin(int i){
//done
    string newBinary("");
    int exp=0, runningTotal=1;
    if(i==0){
        string toReturn("0");
        return toReturn;
    }
    while (runningTotal<=i) {
        runningTotal*=2;
        exp++;
    }
    int numberOfDigits=exp;
    exp--;
    for (int x=0; x<numberOfDigits; x++) {
            if(i==0){
            newBinary.push_back('0');
            continue;
        }
        if (pow(2,exp)<=i) {
            newBinary.push_back('1');
            i -= pow(2,exp);
        } else if (pow(2,exp)>i) {
            newBinary.push_back('0');
        }
            exp--;
    }
    
    return newBinary;
    
}

bool binCheck(int i){
//done
    string toTest = dec2bin(i);
    return pCheck(toTest);
}

bool decCheck(int i){
//done
    char toTest[33];
    sprintf(toTest, "%d", i);
    string tt(toTest);

    return pCheck(tt);
}

bool dbPal(int i){
//done
    bool valid = false;
    valid = decCheck(i);
    if (!valid) {
        return false;
    }
    valid = binCheck(i);
    return valid;
}

int main(int argc, const char * argv[])
{

//    if (pCheck("0110")) {
//        cout << "true\n";
//    }
//    if (!pCheck("0120")) {
//        cout << "false\n";
//    }
// cout << exp(2, 5) << endl;

    //cout << dec2bin(5)<< endl;
    //return 0;
    
    int sum=0;
    for (int i=1; i<1000000; i++) {
        if(dbPal(i)){
            sum+=i;
        }
    }
    cout << sum << endl;
    return 0;
}

