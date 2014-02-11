//
//  main.cpp
//  longestCollatzSequence
//
//  Created by Michael Raimi on 2/6/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{



    map<long,long> dict;
    

  for (int i=1; i<1000000; i++) {
        vector<long> vect;
        long curr = i;
        int moves = 1;
        vect.push_back(curr);
        while (curr!=1) {                           //loop to determine path
            if(dict.find(curr)!=dict.end()){        //lookup to save work
                moves += dict.at(curr);
            break;
            } else {
                if (curr%2) {                       //odd
                    curr = (curr*3)+1;
                    vect.push_back(curr);
                    moves++;
                } else {                            //even
                    moves++;
                    curr /= 2;
                    vect.push_back(curr);
                    
                }
            }
           // cout << moves << endl;
        }
      //end while
      for (vector<long>::iterator iter=vect.begin(); iter!=vect.end(); ++iter) {
          if(dict.find(*iter)==dict.end()){
              dict.emplace(*iter, moves);
          }
              --moves;
      }
      //dict.emplace(i,moves);                        //makes new entry with move count
    //cout << i << endl;
    }
    
    
    long mostMoves=0, candidate;
    for (long j=1;j<1000000;j++) {
        if (dict.at(j)>mostMoves) {
            candidate=j;
            mostMoves=dict[j];
            
        }
    }
    
    cout << candidate << endl;
    cout << mostMoves << endl;
    
    

    return 0;
}

