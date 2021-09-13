//
//  main.cpp
//  Nth Fibonacci
//
//  Created by Federico Xu on 31/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

int getNthFib(int n);
int helper(int n, unordered_map<int, int> &memoize);

int main(int argc, const char * argv[]) {
    cout << getNthFib(10) << endl;
    return 0;
}

int getNthFib(int n){
    unordered_map<int, int> memoize({{1, 0}, {2, 1}});
    return helper(n, memoize);
}

int helper(int n, unordered_map<int, int> &memoize){
    if(memoize.find(n) != memoize.end()){
        return memoize[n];
    }else{
        memoize[n] = helper(n - 1, memoize) + helper(n - 2, memoize);
        return memoize[n];
    }
    
}
