#include <bits/stdc++.h>
using namespace std;

int n, nums[11], minAns = 0x3f3f3f3f, maxAns = -0x3f3f3f3f;
int op[4];

void backtracking(int depth, int result){
    if(depth == n) {
        minAns = min(minAns, result);
        maxAns = max(maxAns, result);
        return;
    }

    if(op[0]){
        op[0]--;
        backtracking(depth+1,result+nums[depth]);
        op[0]++;
    }
    if(op[1]){
        op[1]--;
        backtracking(depth+1,result-nums[depth]);
        op[1]++;
    }
    if(op[2]){
        op[2]--;
        backtracking(depth+1,result*nums[depth]);
        op[2]++;
    }
    if(op[3]){
        op[3]--;
        backtracking(depth+1,result/nums[depth]);
        op[3]++;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> nums[i];
    for(int i = 0; i < 4; i++) cin >> op[i];
    backtracking(1, nums[0]);
    cout << maxAns << '\n' << minAns;
}