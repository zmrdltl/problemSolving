#include <bits/stdc++.h>
using namespace std;
int a[4];
int main(){
    for(int i = 0; i < 4; i++) cin >> a[i];
    if(a[0] > a[1] && a[1] > a[2] && a[2] > a[3]) cout << "Fish Diving";
    else if(a[0] < a[1] && a[1] < a[2] && a[2] < a[3]) cout << "Fish Rising";
    else if(a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) cout << "Fish At Constant Depth";
    else cout << "No Fish";
}