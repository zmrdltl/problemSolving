#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void aristotle(int checkPrime[10001]){
    for(int i = 2; i <= 10000; i++){
        if(!checkPrime[i]) 
            for(int j = i+i; j<10000; j+=i) 
                checkPrime[j] = 1;
    }
}

void printSmallestGap(int n, int checkPrime[10001]){
    pair <int, int> ans(0,0x7f7f7f7f);
    for(int i = 0; i <= n/2; i++){
        if(!checkPrime[i] && !checkPrime[n-i]) {
            if(abs(ans.first-ans.second) > n-i-i){
                ans.first = i;
                ans.second = n-i;
            }
        }
    }
    cout << ans.first << ' ' << ans.second << '\n';
}

int main(){
    fastio;
    int n,t;
    int checkPrime[10001];
    aristotle(checkPrime);

    cin >> t;
    while(t--){
        cin >> n;
        printSmallestGap(n, checkPrime);
    }
}