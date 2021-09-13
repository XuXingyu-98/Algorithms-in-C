//
//  main.cpp
//  Zigzag Traverse
//
//  Created by Federico Xu on 24/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool isOutOfBounds(int row, int col, int heigth, int width);
vector<int> zigzagTraverse(vector<vector<int>> array);
void display(vector<int> array);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> array = {
        {1, 3, 4, 10},
        {2, 5, 9, 11},
        {6, 8, 12, 15},
        {7, 13, 14, 16}
    };
    display(zigzagTraverse(array));
    return 0;
}

bool isOutOfBounds(int row, int col, int heigth, int width){
    return row < 0 || row > heigth || col < 0 || col > width;
}

vector<int> zigzagTraverse(vector<vector<int>> array){
    vector<int> result;
    int row = 0, col = 0;
    int heigth = array.size() - 1;
    int width = array[0].size() - 1;
    bool isGoingDown = true;
    while(!isOutOfBounds(row, col, heigth, width)){
        result.push_back(array[row][col]);
        if(isGoingDown){
            if(col == 0 || row == heigth){
                isGoingDown = false;
                if(row == heigth)
                    col++;
                else
                    row++;
            }else{
                col--;
                row++;
            }
        }else{
            if(row == 0 || col == width){
                isGoingDown = true;
                if(col == heigth)
                    row++;
                else
                    col++;
            }else{
                col++;
                row--;
            }
        }
    }
    return result;
}

void display(vector<int> array){
    for(int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << "\n";
}
