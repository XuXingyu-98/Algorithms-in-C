//
//  main.cpp
//  Nth Fibonacci
//
//  Created by Federico Xu on 31/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
using namespace std;

int getNthFib(int n);

int main(int argc, const char * argv[]) {
    cout << getNthFib(10) << " " << endl;
    return 0;
}

int getNthFib(int n){
    if(n == 2){
        return 1;
    }
    else if (n == 1){
        return 0;
    }
    else{
        return getNthFib(n - 1) + getNthFib(n - 2);
    }
}
