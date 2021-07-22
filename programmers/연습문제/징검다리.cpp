#include <bits/stdc++.h>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(),rocks.end());
    int l = 0;
    int r = distance;

    while(l <= r){
        int mid = (l + r) / 2;
        int rIdx = -1;
        int rCnt = 0;
        for(int i = 0; i <= rocks.size(); i++){
            int d;
            if(i == 0) d = rocks[i];
            else if(i == rocks.size()) d = distance - rocks[rocks.size() - 1];
            else  d = rocks[i] - rocks[rIdx];

            if(d < mid){
                rCnt++;
            }
            else rIdx = i;
        }
        if(rCnt > n){
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return r;
}