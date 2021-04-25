#include <bits/stdc++.h>
using namespace std;
int n, l, x, minusCnt,minusPos,plusPos;
struct Info{ int pos, idx; };
Info ants[100000];
int cmp(Info a, Info b){
    return a.pos < b.pos;
}
int main() {
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x < 0) minusCnt++, minusPos = max(-x, minusPos);
        else plusPos = max(l - x, plusPos);
        ants[i] = { abs(x),i+1 };
    }
    sort(ants, ants + n, cmp);
    if (minusPos > plusPos) cout << ants[minusCnt - 1].idx << ' ' <<  minusPos;
    else cout << ants[minusCnt].idx << ' ' << plusPos;
}
