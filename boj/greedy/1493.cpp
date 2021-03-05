#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int len, wid, hei;
    cin >> len >> wid >> hei;
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for(int i=0 ; i<n ; i++) {
        int a,b;
        cin >> a >> b;
        arr.push_back(make_pair(a,b));
    }

    long long ans=0;
    long long before=0;
    for(int i= 20; i>= 0 ; i--) {
        before <<= 3; // before의 개수를 2^3만큼 늘려준다.
        long long pc = (long long) (len >> i) * (wid >> i) * (hei >> i) - before;
        // 박스를 2^i x 2^i x 2^i만큼 분할해 주고, 전에 박스를 채웠던 큐브의 개수(before)만큼 빼 준다.
        // ex) 4 x 4 x 8이기때문에 4 x 4 x 4로 분할하면 1 x 1 x 2 = 2개가 됨
        long long nc;
        if(i <= n - 1) nc = min((long long) arr[i].second, pc);
        else continue;
        before += nc;
        ans += nc;
    }
    
    if(before == (long long) len * wid * hei) cout << ans;
    else cout << -1;
}