#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, a[12], opNum[4];
int minNum = INF, maxNum = -INF;

void backtracking(int depth, int num){
    //cout <<"depth, num :  "<< depth << ' ' <<num << '\n';
    if(depth == n) {
        maxNum = max(maxNum, num);
        minNum = min(minNum, num);
        return;
    }
    
    if(opNum[0] > 0){
        opNum[0]--;
        backtracking(depth + 1, num + a[depth]);
        opNum[0]++;
    }
    if(opNum[1] > 0){
        opNum[1]--;
        backtracking(depth + 1, num - a[depth]);
        opNum[1]++;
    }
    if(opNum[2] > 0){
        opNum[2]--;
        backtracking(depth + 1, num * a[depth]);
        opNum[2]++;
    }
    if(opNum[3] > 0){
        opNum[3]--;
        backtracking(depth + 1, num / a[depth]);
        opNum[3]++;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < 4; i++) cin >> opNum[i];

    backtracking(1, a[0]);
    cout << maxNum << '\n' << minNum;
}
