//
//  main.cpp
//  Move Element To End
//
//  Created by Federico Xu on 22/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void moveElementToEnd(vector<int> &array, int toMove);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array = {2, 1, 2, 2, 2, 3, 4, 2};
    int toMove = 2;
    moveElementToEnd(array, toMove);
    for(int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << "\n";
    return 0;
}

void moveElementToEnd(vector<int> &array, int toMove){
    int i = 0;
    int j = array.size() - 1;
    while(i < j){
        while(i < j && array[j] == toMove)
            j--;
        if(array[i] == toMove)
            swap(array[i], array[j]);
        i++;
    }
}
