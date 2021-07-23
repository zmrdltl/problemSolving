#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int,int>;
int chapterNum, studyTime;
vector <pii> info(101);
int d[10001][101];
int dp(int t, int n){
    if(t < 0) return -INF;
    if(!n) return 0;
    int &ret = d[t][n];
    if(ret != -1) return ret;
    ret = max(dp(t - info[n].first, n-1) + info[n].second, dp(t, n-1) );
    return ret;
}

int main() {
    memset(d,-1,sizeof(d));
    cin >> chapterNum >> studyTime;
    for(int i = 1; i <= chapterNum; i++)
        cin >> info[i].first >> info[i].second;
    cout << dp(studyTime, chapterNum);
}
