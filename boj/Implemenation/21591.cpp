#include <bits/stdc++.h>
using namespace std;
int w1, h1, w2, h2;
int main() {
    cin >> w1 >> h1 >> w2 >> h2;
    if(w1 - w2 >= 2 && h1 - h2 >= 2) cout << 1;
    else cout << 0;
}