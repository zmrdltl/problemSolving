#include <bits/stdc++.h>
using namespace std;
int b, p;

int getSeaLevel(int p){
    int diff = p - 100;
    if(diff < 0) return 1;
    if(diff == 0) return 0;
    return -1;
}

int main(){
    cin >> b;
    p = 5 * b - 400;
    cout << p << '\n' << getSeaLevel(p);
}