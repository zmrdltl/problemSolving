#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, score;

int main(){
    cin >> n;
    while(n != 1) {
        if(n % 2) n = 3 * n + 1;
        else n/=2;
        score++;
    }
    cout << score;
}