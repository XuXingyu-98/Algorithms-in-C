//
//  main.cpp
//  Nth Fibonacci
//
//  Created by Federico Xu on 24/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

unsigned getNthFibonacci(int n);
unsigned helper(int n, unordered_map<int, unsigned> &memoize);

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << getNthFibonacci(100) << endl;
    return 0;
}

unsigned getNthFibonacci(int n){
    unordered_map<int, unsigned> memoize = {{1, 0}, {2, 1}};
    return helper(n, memoize);
}

unsigned helper(int n, unordered_map<int, unsigned> &memoize){
    if(memoize.find(n) != memoize.end())
        return memoize[n];
    else
        memoize[n] = helper(n - 1, memoize) + helper(n - 2, memoize);
    return memoize[n];
}
