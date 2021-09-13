//
//  main.cpp
//  Lowest Common Manager
//
//  Created by Federico Xu on 27/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class OrgChart{
public:
    char name;
    vector<OrgChart *> directReports;
    
    OrgChart(char name){
        this->name = name;
        this->directReports = {};
    }
    
    void addDirectReports(vector<OrgChart *> directReports);
};

struct OrgInfo{
    OrgChart *lowestCommonManager;
    int numImportantReports;
};

OrgChart *getLowestCommonManager(OrgChart *topManager, OrgChart *reportOne, OrgChart * reportTwo);
OrgInfo getOrgInfo(OrgChart *manager, OrgChart *reportOne, OrgChart *reportTwo);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

OrgChart *getLowestCommonManager(OrgChart *topManager, OrgChart *reportOne, OrgChart * reportTwo){
    return getOrgInfo(topManager, reportOne, reportTwo).lowestCommonManager;
}

OrgInfo getOrgInfo(OrgChart *manager, OrgChart *reportOne, OrgChart *reportTwo){
    int numImportantReports = 0;
    for(OrgChart *directReport: manager->directReports){
        OrgInfo orgInfo = getOrgInfo(directReport, reportOne, reportTwo);
        if(orgInfo.lowestCommonManager != NULL)
            return orgInfo;
        numImportantReports += orgInfo.numImportantReports;
    }
    
    if(manager == reportOne || manager == reportTwo)
        numImportantReports++;
    
    OrgChart *lowestCommonManager = numImportantReports == 2 ? manager : NULL;
    OrgInfo newOrgInfo = {lowestCommonManager, numImportantReports};
    return newOrgInfo;
}
