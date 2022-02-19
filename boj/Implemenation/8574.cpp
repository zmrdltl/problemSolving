#include <bits/stdc++.h>
using namespace std;
int n, unSafeCnt;
double k, x, y, x2, y2;
int main(){
    cin >> n >> k >> x >> y;
    for(int i = 0; i < n; i++){
        cin >> x2 >> y2;
        double dist = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
        if(dist > k) unSafeCnt++;
    }
    cout << unSafeCnt;
}