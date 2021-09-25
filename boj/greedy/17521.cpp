#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, w, coinNum, coinPrice[100001];
int main(){
    cin >> n >> w;
    for(int i = 1; i <= n; i++) cin >> coinPrice[i];

    for(int i = 1; i <= n - 1; i++){
        if(coinPrice[i] < coinPrice[i+1]){
            coinNum = w / coinPrice[i];
            w %= coinPrice[i];
            w += coinPrice[i+1] * coinNum;
        }        
    }

    cout << w;
}