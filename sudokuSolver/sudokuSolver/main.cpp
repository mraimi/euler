//
//  main.cpp
//  sudokuSolver
//
//  Created by Michael Raimi on 2/4/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void rowCheck(int *puzz[][9]){
    int invalidCount=9;
    vector<bool>bv(10, false);
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if(bv.at(puzz[i][j]==false)){
                invalidCount--;
            }
            bv.at(*puzz[i][j])=true;
        }
        if(invalidCount==1){
            for (int j=0; j<10; j++) {
                if(bv.at(j)==false){
                    *puzz[i][j]=i;
                    break;
                }
            }
        }
        bv.assign(10,false);
    }
}

void colCheck(int *puzz[][9]){
    int invalidCount=9;
    vector<bool>bv(10, false);
    for (int j=0; j<10; j++) {
        for (int i=0; i<10; i++) {
            if(bv.at(puzz[i][j]==false)){
                invalidCount--;
            }
            bv.at(*puzz[i][j])=true;
        }
        if(invalidCount==1){
            for (int i=0; i<10; i++) {
                if(bv.at(i)==false){
                    *puzz[j][i]=j;
                    break;
                }
            }
        }
        bv.assign(10,false);
    }
}

void boxCheck(int *puzz[][9]){
    
}

bool isSolved(int *puzz[][9]){
    int count=0;
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            count += *puzz[i][j];
        }
    }
    
    if(count==324){
        return true;
    } else {
        return false;
    }
}

int solve(int *total, int *puzz[][9]){
    int toReturn=-1;
    bool solved = isSolved(puzz);
    
    while (!solved) {
        rowCheck(puzz);
        colCheck(puzz);
        boxCheck(puzz);
    }
    return toReturn;
}

void printPuzzle(int *puzz[9][9]){
    int row=0, column=0;
    for (int i=0; i<81; i++) {
        cout << puzz[row][column] << "  ";
        if (column==8) {
            row++;
            column=0;
            cout << "\n";
            continue;
        }
        column++;
    }
    cout << "\n\n\n";
}



bool topRightCheck(int arr[9][9]){
    if (arr[0][1] && arr[0][2] && arr[0][3]){
        return true;
    }
    return false;
}



int main(int argc, const char * argv[])
{
    int *puzzle[9][9];
    int count=0, total=0, row=0, column=0;
    total++;
    string line, stringDoc;
    ifstream doc;
    doc.open("sudoku.txt");
    
    if(doc.is_open()){
        while (getline(doc, line)){
            stringDoc.append(line);
            count++;
        }
    } else {
        cout << "file error\n";
    }
    
    count=0;
    
    for (int i=0; i<stringDoc.length(); i++) {
        if (count<7) {
            count++;
            continue;
        } if(count==87){
            char c = stringDoc.at(i);
            int toAdd = c-48;
            *puzzle[row][column]=toAdd;
            solve(&total, puzzle);
            printPuzzle(puzzle);
            row=0;column=0;
            count=0;
        } else {
            char c = stringDoc.at(i);
            int toAdd = c-48;
            *puzzle[row][column]=toAdd;
            if (column==8) {
                row++;column=0;
            }
            column++;
            count++;
        }
    }
    
        return 0;
}

