#include <bits/stdc++.h>
using namespace std;
int lgcd[1000010], rgcd[1000010], a[1000010], n;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) lgcd[i] = gcd(a[i],lgcd[i-1]);
    for(int i = n; i >= 1; i--) rgcd[i] = gcd(a[i],rgcd[i+1]);

    int deletedNum = -1;
    int bigGCD = 0;
    for(int i = 1; i <= n; i++){
        int gcdResult = gcd(lgcd[i-1],rgcd[i+1]);
        if(gcdResult > bigGCD && (a[i] % gcdResult)){
            bigGCD = gcdResult;
            deletedNum = a[i];
        }
    }

    if(deletedNum == -1) cout << -1;
    else cout << bigGCD << ' ' << deletedNum;
}