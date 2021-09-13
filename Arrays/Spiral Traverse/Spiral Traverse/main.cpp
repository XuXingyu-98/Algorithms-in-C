//
//  main.cpp
//  Spiral Traverse
//
//  Created by Federico Xu on 23/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array);
void spiralFill(vector<vector<int>> array, int startRow, int endRow, int startCol, int endCol, vector<int> &result);
void display(vector<int> array);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> array = {
        {1, 2, 3, 4},
        {12, 13, 14, 5},
        {11, 16, 15, 6},
        {10, 9, 8, 7}
    };
    vector<int> result = spiralTraverse(array);
    display(result);
    return 0;
}

vector<int> spiralTraverse(vector<vector<int>> array){
    vector<int> result = {};
    spiralFill(array, 0, array.size() - 1, 0, array[0].size() - 1, result);
    return result;
}

void spiralFill(vector<vector<int>> array, int startRow, int endRow, int startCol, int endCol, vector<int> &result){
    if(startRow > endRow || startCol > endCol)
        return;
    
    int row, col;
    
    for(col = startCol; col <= endCol; col++)
        result.push_back(array[startRow][col]);
    
    for(row = startRow + 1; row <= endRow; row++)
        result.push_back(array[row][endCol]);
    
    for(col = endCol - 1; col >= startCol; col--){
        if(startRow == endRow)
            break;
        result.push_back(array[endRow][col]);
    }
    
    for(row = endRow - 1; row >= startRow + 1; row--){
        if(startCol == endCol)
            break;
        result.push_back(array[row][startCol]);
    }
    
    spiralFill(array, startRow + 1, endRow - 1, startCol + 1, endCol - 1, result);
}

void display(vector<int> array){
    for(int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << "\n";
}
