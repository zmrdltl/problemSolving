//nlogn dp
#include <bits/stdc++.h>
using namespace std;

int n, d[1001],a[1001],lcs;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        auto *pos = lower_bound(a + 1, a + lcs + 1, a[i]);
        *pos = a[i];
        if(pos == a + lcs + 1) lcs++;
    }
    cout << lcs;
}