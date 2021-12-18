#include <bits/stdc++.h>
using namespace std;
int n, aScore, bScore;
int main(){
    cin >> n;
    for(int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        if(a > b) aScore += a + b;
        else if(a == b) aScore += a, bScore += b;
        else bScore += a + b;
    }
    cout << aScore << ' ' << bScore;
}