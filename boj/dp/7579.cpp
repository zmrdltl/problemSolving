#include <bits/stdc++.h>
using namespace std;

int appNum, needMem;
int mem[101], cost[101], d[101][10001];

int dp(int cur, int memLeft){
    if(cur == appNum) return 0;
    int &ret = d[cur][memLeft];
    if(ret!=-1) return ret;
    ret = dp(cur+1,memLeft);
    if(memLeft >= cost[cur]) ret = max(ret,mem[cur] + dp(cur+1,memLeft - cost[cur]));
    return ret;
}

int main(){
    cin >> appNum >> needMem;
    for(int i = 0; i < appNum; i++) cin >> mem[i];
    for(int i = 0; i < appNum; i++) cin >> cost[i];
    memset(d,-1,sizeof(d));
    int memory = 0;
    while(1){
        if(dp(0,memory)>=needMem) {
            cout << memory;
            break;
        }
        memory++;
    }
}