#include <bits/stdc++.h>
using namespace std;

int fomula(int h, int M){
    for(int t = 1; t <= M; t++){
        int a = -6*pow(t,4) + h*pow(t,3) + 2 *pow(t,2) + t;
        if(a <= 0) return t;
    }
    return 0;
}

int main(){
    int h, M, ans;
    cin >> h >> M;
    ans = fomula(h,M);
    if(!ans) cout << "The balloon does not touch ground in the given time.";
    else cout << "The balloon first touches ground at hour: " << ans;
}