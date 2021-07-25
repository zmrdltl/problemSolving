#include <bits/stdc++.h>
using namespace std;
int n, m, a[101];

int bruteForce(int idx, int cnt, int size){
    if(cnt > m) return 0;
    if(cnt == m) return size;
    int ans = 0;
    ans = max(bruteForce(idx + 1, cnt + 1, size + a[idx+1]), bruteForce(idx + 2, cnt + 1, size/2 + a[idx+2]));
    return ans;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << bruteForce(0,0,1);
}