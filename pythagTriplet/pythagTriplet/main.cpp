//
//  main.cpp
//  pythagTriplet
//
//  Created by Michael Raimi on 2/4/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{

        
        for(int a=1;a<=1000;a++){
            for(int b=a+1;b<=1000;b++){
                for(int c=b+1;c<=1000;c++){
                    if(a<b<c && a+b+c==1000 && (a*a+b*b==c*c)){
                        cout << a*b*c << "\n";
                        return 0;
                    }
                }
            }
        }
                    return 0;
}

