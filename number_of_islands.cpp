//
//  number_of_islands.cpp
//  NumberOfIslands
//
//  Created by Roberto Merlos on 3/16/19.
//  Copyright © 2019 RAMG. All rights reserved.
//
// This code demonstrates a solution for the common Number of Islands problem.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class type>
void display(vector<vector<type>> m, string title=""){
    int rows = m.size();
    int columns = m[0].size();
    
    cout<<title;
    for(int r=0;r<rows;r++){
        for(int c=0;c<columns;c++){
            cout<<m[r][c]<<'\t';
        }
        cout<<'\n';
    }
}

bool inBounds(vector<vector<char>> grid, int r, int c){
    int rows = grid.size();
    int columns = grid[0].size();
    return (r >= 0 && r < rows && c >= 0 && c < cols);
}

void check(vector<vector<char>> & grid, int r, int c){
    if(!inBounds(r, c)) return;
    if(grid[r][c] != '1') return;
    
    grid[r][c] = 'i';
   
    // down
    check(grid, r+1, c);
    
    // up
    check(grid, r-1, c);
    
    // left
    check(grid, r, c-1);
    
    // right
    check(grid, r, c+1);
}

int islands(vector<vector<char>> & grid){
    int rows = grid.size();
    int columns = grid[0].size();
    
    int components = 0;
    for(int r=0;r<rows;++r){
        for(int c=0;c<columns;++c){
            if(grid[r][c] == '1'){
                check(grid, r, c);
                components++;
            }
        }
    }
    return components;
}

int main() {
    
    // How many islands?
    
    vector<vector<char>> m;
    m.push_back(vector<char> {'1','0','0','0'});
    m.push_back(vector<char> {'1','1','1','1'});
    m.push_back(vector<char> {'0','0','0','0'});
    m.push_back(vector<char> {'1','0','1','0'});
    
    cout<<"-------\n";
    display(m, "Matrix:\n");
    cout<<"-------\n\n";
   
    int result = islands(m);
    cout<<"\n\n-------------------------\n";
    cout<<"* Number of Islands: "<<result<<"\n";
    cout<<"-------------------------\n\n";
    
    return 0;
}
