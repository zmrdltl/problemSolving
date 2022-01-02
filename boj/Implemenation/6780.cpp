#include <bits/stdc++.h>
using namespace std;
int t1, t2, t3, cnt;
int main(){
    cin >> t1 >> t2;
    while(t1 >= t2){
        t3 = t1 - t2;
        t1 = t2;
        t2 = t3;
        cnt++;
    }
    cout << cnt + 2;
}