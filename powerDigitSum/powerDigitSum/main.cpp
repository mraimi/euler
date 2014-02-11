//
//  main.cpp
//  powerDigitSum
//
//  Created by Michael Raimi on 2/5/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <iostream>
#include <string>
//#include <cstdlib>


using namespace std;

void sumHelper(string s){
    cout << s << "\n";
    int total=0;
    char c;
    for (string::iterator iter=s.begin(); iter!=s.end(); iter++) {
        c = *iter;
        int i = c - '0';
        total += i;
    }
    cout << "Sum Total:" <<total << "\n";
    
}

void sumTwoToTheN(int exp){
    std::string s("1");
    int carry=0;
    for (int i=0; i<exp; i++) {
        int pos = (int)s.length()-1;
        while (pos>=0) {
            int currDig = s.at(pos)-48;
            s.at(pos)= '0'+((currDig*2)+carry)%10;
            if((currDig*2+carry)>9){
                carry=1;
            } else {
                carry=0;
            }
            
            if(carry){
                if(pos==0){
                  s.insert(pos, "1");
                    carry--;
                    break;}
            }
            pos--;
        }
    }
    cout << "2^" << exp << " = ";
    sumHelper(s);
}

int main(int argc, const char * argv[])
{

    sumTwoToTheN(1000);
    return 0;
}

