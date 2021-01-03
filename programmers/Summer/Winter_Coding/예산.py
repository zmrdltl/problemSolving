#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int ck[101];
int answer= 0 ;

int solution(vector<int> d, int budget) {
    sort(d.begin(),d.end());
    int cur = 0;
    for(int i = 0; i < d.size(); i++){
        ck[cur+d[i]]++;
        cur = d[i];
    }

    return d[budget];
}