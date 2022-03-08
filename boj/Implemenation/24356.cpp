#include <bits/stdc++.h>
using namespace std;
int t1, m1, t2, m2, diff;
int main(){
    cin >> t1 >> m1 >> t2 >> m2;
    m1 += t1 * 60, m2 += t2 * 60;
    if(m1 > m2) m2 += 24 * 60;
    diff = m2 - m1;
    cout << diff << ' ' << diff / 30;
}