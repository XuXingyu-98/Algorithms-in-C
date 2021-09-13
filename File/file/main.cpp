//
//  main.cpp
//  hello world
//
//  Created by Federico Xu on 20/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream inFile("foo.txt");
    if(!inFile.is_open())
        cout << "Non va bene";
    string firstname, lastname;
    int age, bmonth, bday, byear;
    while(inFile >> firstname >> lastname >> age >> bmonth >> bday >> byear)
        printf("%s %s %d %d %d %d\n", firstname.c_str(), lastname.c_str(), age, bmonth, bday, byear);
    return 0;
}
