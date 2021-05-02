#include <bits/stdc++.h>
using namespace std;
double k,d1,d2,n;
int main(){
    cin >> k >> d1 >> d2;
    n = (max(d1,d2)-min(d1,d2)) / 2.0;
    cout << k * k - n * n;
}