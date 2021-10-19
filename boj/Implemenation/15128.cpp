#include <bits/stdc++.h>
using namespace std;
long long p1, q1, p2, q2;
int main(){
    cin >> p1 >> q1 >> p2 >> q2;
    cout << (p1 * p2 % (q1 * q2 * 2) == 0);
}
