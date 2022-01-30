#include <bits/stdc++.h>
using namespace std;
int n, minN, maxN;
int main(){
    cin >> n;
    for(int i = 2; i <= n; i++) {
        if(n % i) { minN = i; break; }
    }
    for(int i = n - 1; i >= 2; i--) {
        if(n % i) { maxN = i; break; }
    }
    cout << minN << ' ' << maxN;
}