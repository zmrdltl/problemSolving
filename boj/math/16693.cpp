#include <bits/stdc++.h>
using namespace std;
double a1, p1, r1, p2;
int main() {
    cin >> a1 >> p1 >> r1 >> p2;
    double wholePizzaValue = r1 * r1 * 3.14159265359 / p2;
    double slicePizzaValue = a1 / p1;
    if(wholePizzaValue > slicePizzaValue) cout << "Whole pizza";
    else cout << "Slice of pizza";
}