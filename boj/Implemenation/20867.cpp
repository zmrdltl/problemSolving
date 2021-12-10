#include <bits/stdc++.h>
using namespace std;
int m, s, g, l, r;
double a, b;
int ls, rs, lwait, rwait;
int main(){
    cin >> m >> s >> g >> a >> b >> l >> r;
    lwait = l / a, rwait = r / b;
    ls = m % g ? m / g + 1 : m / g; 
    rs = m % s ? m / s + 1 : m / s; 
    if(ls < rs) {
        if(ls + lwait < rs + rwait) cout << "friskus";
        else cout << "latmask";
    }
    else {
        if(ls + lwait < rs + rwait) cout << "friskus";
        else cout << "latmask";
    }
}