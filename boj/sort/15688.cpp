#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n;
int num[200'0001];
int main(){
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num[x + 1000000]++;
    }
    for(int i = 0; i <= 2000000; i++){
        if(!num[i]) continue;
        while(num[i]--) cout << i - 1000000 << '\n';
    }
}