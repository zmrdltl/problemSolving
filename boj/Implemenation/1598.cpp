#include <bits/stdc++.h>
using namespace std;
struct Coord {int r, c; };
int n1, n2;

Coord getCoord(int num){
    int r, c;
    r = num % 4;
    if(!r) r = 4;
    c = num / 4;
    if(num % 4 == 0) c--;
    return {r, c};
}

int main(){
    cin >> n1 >> n2;
    Coord x = getCoord(n1);
    Coord y = getCoord(n2);
    cout << abs(x.r - y.r) + abs(x.c - y.c);
}