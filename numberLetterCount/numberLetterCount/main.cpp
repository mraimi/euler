//
//  main.cpp
//  numberLetterCount
//
//  Created by Michael Raimi on 2/28/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

string int_to_string(int n, std::map<int, string> &d){
    std::map<int,string> dict = d;
    string toReturn("");
    int temp = n;
    
    if (n==1000) {
        //cout << "one-thousand"<<endl;
        return "one-thousand";
    }
    
    if (temp>=100) {
        string test = dict[((int)temp/100)];
        toReturn+= dict[((int)temp/100)];
        toReturn+=" hundred";
        if (temp%100) {
            toReturn += " and ";
        }
        temp = temp%100;
        
    }
    
    if(temp>19){
        
        toReturn+=dict[((int)temp/10)*10];
        if(temp%10)
            toReturn+="-";
        temp = temp%10;
    }
    if (temp) {
        
        toReturn += dict[temp];
    }
    
    //cout << toReturn << endl;
    
    
    
    return toReturn;
    
}

int parse(string s){
    int count = 0;
    for (int i=0; i<s.length(); i++) {
        if (s.at(i) != ' ' && s.at(i)!='-') {
            count++;
        }
    }
    return count;
}


int let_count_span (int low, int high){
    int runningCount = 0;
    
    std::map<int, string> dict;
    
    dict[1]="one";
    dict[2]="two";
    dict[3]="three";
    dict[4]="four";
    dict[5]="five";
    dict[6]="six";
    dict[7]="seven";
    dict[8]="eight";
    dict[9]="nine";
    dict[10]="ten";
    dict[11]="eleven";
    dict[12]="twelve";
    dict[13]="thirteen";
    dict[14]="fourteen";
    dict[15]="fifteen";
    dict[16]="sixteen";
    dict[17]="seventeen";
    dict[18]="eighteen";
    dict[19]="nineteen";
    dict[20]="twenty";
    dict[30]="thirty";
    dict[40]="forty";
    dict[50]="fifty";
    dict[60]="sixty";
    dict[70]="seventy";
    dict[80]="eighty";
    dict[90]="ninety";
    
  
    
    for (int i=low; i<=high; i++){
        
        runningCount += parse(int_to_string(i, dict));
        
    }
    
    return runningCount;
}


int main(int argc, const char * argv[])
{

    
    cout << let_count_span(1,1000) << endl;
    return 0;
}

