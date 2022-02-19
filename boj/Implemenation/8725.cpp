#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, sum;
int main(){
    cin >> n;
    for(int i = 0, x; i < n; i++) {
        int maxNum = -INF;
        for(int j = 0; j < n; j++){
            cin >> x;
            maxNum = max(maxNum, x);
        }
        if(maxNum > 0) sum += maxNum;
    }
    cout << sum;
}