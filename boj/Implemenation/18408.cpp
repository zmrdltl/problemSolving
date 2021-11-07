#include <bits/stdc++.h>
using namespace std;
int a[3], cnt;
int main(){
    for(int i = 0, x; i < 3; i++) {
        cin >> x;
        a[x]++;
    }
    for(int i = 0; i < 3; i++) {
        cnt = max(cnt, a[i]);
    }
    for(int i = 0; i < 3; i++) {
        if(cnt == a[i]) {cout << i; break;}
    }
}