//
//  main.cpp
//  reverseStringByWords
//
//  Created by Michael Raimi on 1/26/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>


using namespace std;

stack<string> reverse(stack<string> s, string str){
    int cur=0,i;
    string toAdd;
    
    for (i=0; i<str.length(); i++) {
        if (str.at(i)==' ') {
            if(cur==i){
                
                continue;
            } else {
                toAdd = str.substr(cur,(i+1-cur));
                s.push(toAdd);
                //cout << toAdd << "\n";
                cur=i+1;
            }
        }
        if(i==str.length()-1){
            toAdd=str.substr(cur,str.length()-cur);
            toAdd.push_back(' ');
            s.push(toAdd);
            //cout <<  toAdd << "\n";
        }
        
    }
    return s;
}

int main(int argc, const char * argv[])
{
    stack<string> s;
    string str("Please reverse this string word by word");
    s = reverse(s,str);
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    cout << "\n";
    
    
    return 0;
}

