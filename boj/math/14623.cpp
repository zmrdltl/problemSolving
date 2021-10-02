#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long x, y, z;
string a, b;
int r[101], f;
int main() {
    cin >> a >> b;
    for (int i = a.length() - 1; i >= 0; i--) {
        if (a[i] == '1')
            x += (1 << (a.length() - 1 - i));
    }
    for (int i = b.length() - 1; i >= 0; i--) {
        if (b[i] == '1')
            y += (1 << (b.length() - 1 - i));
    }
    z = x*y;
    for (int i = 0; i < 63; i++) {
        if ((1LL << i)&z)
            r[i] = 1;
    }
    for (int i = 100; i >= 0; i--) {
        if (!f&&r[i])
            f = 1;
        if (f)
            printf("%d", r[i]);
    }
    return 0;
}

