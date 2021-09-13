//
//  main.cpp
//  test
//
//  Created by Federico Xu on 15/09/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
using namespace std;

int &test(int *n);

int main(int argc, const char * argv[]) {
    int n = 0;
    int p = test(&n);
    cout << p << endl;
    return 0;
}

int &test(int *n){
    *n = 5;
    return *n;
}
