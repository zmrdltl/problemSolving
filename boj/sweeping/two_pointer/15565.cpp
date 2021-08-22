//귀여운 라이언
#include <bits/stdc++.h>
using namespace std;
int n, k, length = 0x3f3f3f3f;
vector <int> lionIdx;
int main(){
    cin >> n >> k;
    for(int i = 0,x; i < n; i++) {
        cin >> x;
        if(x == 1) lionIdx.push_back(i);
    }

    int lsize = lionIdx.size();

    for(int i = 0; i <= lsize - k; i++){
        length = min(length, lionIdx[i + k - 1] - lionIdx[i] + 1);
    }

    if(length == 0x3f3f3f3f) cout << -1;
    else cout << length;
}