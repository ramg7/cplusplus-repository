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
void display(vector<vector<type>> vv, string title=""){
    int rows = vv.size();
    int columns = vv[0].size();
    
    cout<<title<<"\n";
    for(int r=0;r<rows;r++){
        for(int c=0;c<columns;c++){
            cout<<vv[r][c]<<" ";
        }
        cout<<endl;
    }
}

int check(vector<vector<char>> & grid, vector<vector<bool>> & visited, int r, int c){
    
    int rows = grid.size();
    int columns = grid[0].size();
    
    if(r > rows || c > columns || r < 0 || c < 0 || grid[r][c] != '1' || visited[r][c]) return 1;
    
    int tr, tc;
    
    // Origin
    // e.g: 0 0
    if(grid[r][c] == '1')
        visited[r][c] = true;
    
    // Down
    // e.g: 1 0
    tr = r+1;
    tc = c;
    while(tr < rows && grid[tr][tc] == '1'){
        check(grid, visited, tr, tc);
        //        visited[tr++][tc] = true;
        //        or
        ++tr;
    }
    
    // Up
    // e.g: -1 0
    //    if(r == rows - 1){
    tr = r-1;
    tc = c;
    while(tr > 0 && grid[tr][tc] == '1'){
        check(grid, visited, tr, tc);
        --tr;
    }
    //    }
    
    // Right
    // e.g: 0 1
    tr = r;
    tc = c+1;
    while(tc < columns && grid[tr][tc] == '1'){
        check(grid, visited, tr, tc);
        ++tc;
    }
    
    // Left
    // e.g: 0 -1
    tr = r;
    tc = c-1;
    while(tc > 0 && grid[tr][tc] == '1'){
        check(grid, visited, tr, tc);
        --tc;
    }
    
    // Diagonal
    // e.g: 1 1
    tr = r+1;
    tc = c+1;
    while(tr < rows && tc < columns && grid[tr][tc] == '1'){
        check(grid, visited, tr, tc);
        ++tr;
        ++tc;
    }
    
    return 0;
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
    
    vector<vector<bool>> v;
    v.push_back(vector<bool> (m[0].size(), false));
    v.push_back(vector<bool> (m[0].size(), false));
    v.push_back(vector<bool> (m[0].size(), false));
    v.push_back(vector<bool> (m[0].size(), false));
    
    
    cout<<"-------\n";
    display(m, "Matrix:");
    cout<<"-------\n\n";
    
    cout<<"-------\n";
    display(v, "Visited (Before):");
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
