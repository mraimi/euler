//
//  main.cpp
//  factorialDigitSum
//
//  Created by Michael Raimi on 2/9/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

void digitSum(){
    

}

//std::string factorial(int limit){
//    
//    char s[10000];
//    sprintf(s, "%d", limit);
//    
//    std::string str(s);
//    
//    int carry=0, current = limit-1;
//    
//    while (limit>1) {
//        //prev=limit;
//        while (current) {
//
//            for (std::string::reverse_iterator iter=str.rbegin(); iter!=str.rend(); iter++) {
//                char c = *iter;
//                int fromString = atoi(&c);
//                int toWrite;
//                    toWrite=((((current%10)*fromString)+carry)%10);
//                char tw = '0'+toWrite;
//                *iter = tw;
//                carry = (current%10)*fromString-toWrite;
//            }
//            
//            current /= 10;
//            limit--;
//        }
//    }
//    return str;
//    
//}
//
//std::string addStrings(std::string s1, std::string s2){
//    std::string sum(s1);
//    std::string::reverse_iterator i1 = sum.rbegin();
//    std::string::reverse_iterator i2 = s2.rbegin();
//    
//    while (i1!=sum.rend() && i2!=s2.rend()) {
//        <#statements#>
//    }
//
//    
//    
//    
//    
//}
































int str_summer(string s){
//done, checked
    int sum=0;
    for (int i=(int)s.length()-1; i>=0; i--) {
        int x = s.at(i) - '0';
        sum += x;
    }
    
    return sum;
    
}


string add(string s1, string s2){
//done, checked
    string toReturn("");
    string top, bottom;
    int carry = 0;
    
    if (s1.length()>s2.length()) {
        top = s1;
        bottom = s2;
    } else {
        top = s2;
        bottom = s1;
    }
    
    /*
        Above accounts for differening length strings s.t. biggest 
        becomes the top number
    */
    
    for (int i=(int)top.length()-1; i>=0; i--) {
        
        char t, b;
        int diff = (int)top.length() - (int)bottom.length();
        if (i < (diff)){
            t = top.at(i);
            b = '0';
        } else {
            t = top.at(i);
            b = bottom.at(i - diff);
        }
        
     /*
        We now have the chars of the current digits to sum
     */
        
        int t_i = t - '0';
        int b_i = b - '0';
        
     /*
        We now have the ints of the current digits to sum
     */
        char toWrite = ((t_i + b_i + carry) % 10) + '0';

        if (t_i + b_i + carry > 9) {
            carry = 1;
        } else {
            carry = 0;
        }
        
        
        toReturn.insert(toReturn.begin(), toWrite);
        
        if (i==0 && carry==1){
            toReturn.insert(toReturn.begin(), '1');
        }
    }
    return toReturn;
    
    
}




string multiply(string s, int n){
//done, checked
    
    string runningTotal(s);
    
    for (int i=0; i<n-1; i++) {
        runningTotal = add(runningTotal,s);
    }
    
    return runningTotal;
    
}






int factorial(int n){
//done
    string toReturn("");
    
    int i=n;
    char str[33];
    sprintf(str, "%d", n);
    string current(str);

    while (i>1) {
        current = multiply(current,i-1);
        i--;
    }
    
    return str_summer(current);
}







int main(int argc, const char * argv[])
{
    //cout << add("1235", "048") << endl;
    //cout << str_summer("12345") << endl;
    //cout << multiply("011", 5) << endl;
    cout << factorial(100) << endl;
    return 0;
}

