#include <bits/stdc++.h>
using namespace std;
int x, y, ans = 1;
int main(){
    cin >> x >> y;
    for(; (y - x) * ans < y; ans++);
    cout << ans;   
}