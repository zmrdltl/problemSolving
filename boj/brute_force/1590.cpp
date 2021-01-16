#include <bits/stdc++.h>
using namespace std;
int waitTime = 0x7f7f7f7f;
struct Bus{ int startTime, gapTime, busCount; };
Bus busInfo[100000];
int main(){
    int n;
    int goal;
    cin >> n >> goal;
    for(int i = 0; i < n; i++){
        cin >> busInfo[i].startTime >> busInfo[i].gapTime >> busInfo[i].busCount;
    }
    
    for(int i = 0; i < n; i++){
        int startTime = busInfo[i].startTime;
        int gapTime = busInfo[i].gapTime;
        int leftTime = goal - startTime;
        int nthBus = leftTime % gapTime <= 0 ? (leftTime / gapTime) : (leftTime / gapTime + 1);
        if(nthBus < 0) nthBus=0;
        int arriveTime = startTime + gapTime * nthBus;
        if(nthBus < busInfo[i].busCount) 
            waitTime = min (waitTime,arriveTime - goal);
    }
    if(waitTime == 0x7f7f7f7f) cout << "-1";
    else cout << waitTime << '\n';
}