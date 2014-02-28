//
//  main.cpp
//  thousandDigitFibo
//
//  Created by Michael Raimi on 2/28/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


int dig_count(string s){
//done
    return (int)s.length();
}

string fibo_str(string one, string two){
//done, tested
    string toReturn("");
    int carry = 0;
    string top, bottom;
    if (one.length()>=two.length()) {
        top = one;
        bottom = two;
    } else {
        bottom = one;
        top = two;
    }
    
    for (int i=(int)top.length()-1; i>=0; i--) {
        int difference = (int)top.length()- (int)bottom.length();
        char t,b;
        if(i<difference){
            b='0';
        } else {
            b = bottom.at(i-difference);
        }
            t = top.at(i);
        
        
        int sum = (t-'0')+(b-'0')+carry;
        if (sum>9) {
            carry=1;
        } else {
            carry=0;
        }
        char toWrite = '0'+(sum % 10);
        toReturn.insert(toReturn.begin(), toWrite);
        if(i==0 && carry==1){
            toReturn.insert(toReturn.begin(), '1');
        }
        
    }
    
    return toReturn;
}

int n_dig_fibo(int numberOfDigits){
    int current=2, currentLength=1;
    string one("1"), two("1");
    while (currentLength<numberOfDigits) {
        current++;
        string temp = fibo_str(one, two);
        currentLength = dig_count(temp);
        one = two;
        two = temp;
        
    }
    
    return current;
    
}

int main(int argc, const char * argv[])
{
    
    
    cout << n_dig_fibo(1000) <<endl;
    
    return 0;
}

