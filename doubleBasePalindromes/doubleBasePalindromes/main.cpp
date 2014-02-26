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



/* ------------------------------------------------------------------
    dec2bin is a hard coded base conversion from 10 to 2
    dec2base is a more general implentation of base conversion
 ------------------------------------------------------------------ */


string dec2base(int decimal, int base){
//done
    string toReturn("");
    
    if (base==0) {
        return "ERROR";
    }
    
    if (decimal==0){
        return "0";
    }
    
    int divisor = base;
    int dividend = decimal;
    int quotient = (int) dividend/divisor;
    int toPush = dividend % divisor;
    
    char tp = '0'+toPush;
    toReturn.insert(toReturn.begin(), tp);

    while (quotient !=0) {
        dividend = quotient;
        quotient = dividend/divisor;
        toPush = dividend % divisor;
        char tp = '0'+toPush;
        toReturn.insert(toReturn.begin(), tp);
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
    cout << dec2base(123, 0) << endl;
    return 0;
    
    int sum=0;
    for (int i=1; i<1000000; i++) {
        if(dbPal(i)){
            sum+=i;
        }
    }
    cout << sum << endl;
    return 0;
}

