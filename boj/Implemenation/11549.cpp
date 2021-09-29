#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int main(){
    cin >> n;
    for(int i = 0,x; i < 5; i++){
        cin >> x;
        if(x == n) cnt++;
    }
    cout << cnt;
}