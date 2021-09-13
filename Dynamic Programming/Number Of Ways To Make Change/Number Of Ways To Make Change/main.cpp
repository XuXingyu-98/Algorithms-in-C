//
//  main.cpp
//  Number Of Ways To Make Change
//
//  Created by Federico Xu on 27/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> denoms = {1, 5, 10, 25};
    int n = 25;
    cout << numberOfWaysToMakeChange(n, denoms) << endl;
    return 0;
}

int numberOfWaysToMakeChange(int n, vector<int> denoms){
    vector<int> ways(n + 1, 0);
    ways[0] = 1;
    for(int denom: denoms)
        for(int amount = 1; amount < n + 1; amount++)
            if(denom <= amount)
                ways[amount] += ways[amount - denom];
    return ways[n];
}
