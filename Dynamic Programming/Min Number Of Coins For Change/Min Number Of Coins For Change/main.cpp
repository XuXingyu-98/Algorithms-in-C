//
//  main.cpp
//  Min Number Of Coins For Change
//
//  Created by Federico Xu on 27/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> denoms = {39, 45, 130, 40, 4, 1, 60, 75};
    int n = 135;
    cout << minNumberOfCoinsForChange(n, denoms) << endl;
    return 0;
}

int minNumberOfCoinsForChange(int n, vector<int> denoms){
    vector<int> numOfCoins(n + 1, INT_MAX);
    numOfCoins[0] = 0;
    int toCompare = 0;
    for(int denom: denoms)
        for(int amount = 1; amount < numOfCoins.size(); amount++)
            if(denom <= amount){
                if(numOfCoins[amount - denom] == INT_MAX)
                    toCompare = numOfCoins[amount - denom];
                else
                    toCompare = numOfCoins[amount - denom] + 1;
                
                numOfCoins[amount] = min(toCompare, numOfCoins[amount]);
            }
    return numOfCoins[n] != INT_MAX ? numOfCoins[n] : -1;
}
