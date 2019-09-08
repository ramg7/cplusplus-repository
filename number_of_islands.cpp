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

void check(vector<vector<char>> & grid, vector<vector<bool>> & visited, int r, int c){
    
    int rows = grid.size();
    int columns = grid[0].size();
    
    if(r >= rows || c >= columns || r < 0 || c < 0 || grid[r][c] == '0' || visited[r][c]) return;
    
    visited[r][c] = true;
   
    // down
    check(grid, visited, r+1, c);
    
    // up
    check(grid, visited, r-1, c);
    
    // left
    check(grid, visited, r, c-1);
    
    // right
    check(grid, visited, r, c+1);
}

int islands(vector<vector<char>> & grid, vector<vector<bool>> & visited){
    int rows = grid.size();
    int columns = grid[0].size();
    
    int components = 0;
    for(int r=0;r<rows;++r){
        for(int c=0;c<columns;++c){
            if(grid[r][c] == '1' && !visited[r][c]){
                check(grid, visited, r, c);
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
    
    vector<vector<bool>> v(m.size(), vector<bool> (m[0].size(), false));    
    
    cout<<"-------\n";
    display(m, "Matrix:\n");
    cout<<"-------\n\n";
    
    cout<<"-------\n";
    display(v, "Visited (Before):\n");
    cout<<"-------\n";
    cout<<"Processing ...\n";
    int result = islands(m, v);
    cout<<"-------\n";
    display(v, "Visited (After):");
    cout<<"-------";
    
    cout<<"\n\n-------------------------\n";
    cout<<"* Number of Islands: "<<result<<"\n";
    cout<<"-------------------------\n\n";
    
    return 0;
}
