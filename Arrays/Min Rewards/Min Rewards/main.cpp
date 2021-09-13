//
//  main.cpp
//  Min Rewards
//
//  Created by Federico Xu on 24/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int minRewards(vector<int> scores);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> scores = {8, 4, 2, 1, 3, 6, 7, 9, 5};
    cout << minRewards(scores) << endl;
    return 0;
}

int minRewards(vector<int> scores){
    vector<int> rewards = vector<int>(scores.size(), 1);
    for(int i = 1; i < scores.size(); i++)
        if(rewards[i] > rewards[i - 1])
            rewards[i] = rewards[i - 1] + 1;
    for(int i = scores.size() - 2; i >= 0; i--)
        if(scores[i] > scores[i + 1])
            rewards[i] = max(rewards[i], rewards[i + 1] + 1);
    return accumulate(rewards.begin(), rewards.end(), 0);
}
