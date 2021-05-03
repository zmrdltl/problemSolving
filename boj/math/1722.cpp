#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, op, ans = 1;
ll factorial[21] = {1};
ll ck[21];
int main(){
    cin >> n >> op;
    vector <ll> comb(n+1);
    for(int i = 1; i <= n; i++) factorial[i] = factorial[i-1] * i; 

    if(op == 1){
        cin >> k; //3
        
        for(int i = 1; i <= n; i++){ //i¹øÂ° ÀÚ¸®
            for(int j = 1; j <= n; j++){ //j¼ö
                if(ck[j]) continue;
                if(factorial[n-i] < k){ //skip¸¶´Ù n-i!¾¿ »©ÁÜ
                    k -= factorial[n-i];
                }
                else{
                    comb[i] = j;
                    ck[j] = 1;
                    break;
                }
            }
        }

        for(int i = 1; i <= n; i++) cout << comb[i] << ' ';

    }
    else{
        for(int i = 1; i <= n; i++) cin >> comb[i];

        for(int i = 1; i <= n; i++){
            for(int j = 1; j < comb[i]; j++){
                if(ck[j]) continue;
                ans += factorial[n-i];
            }
            ck[comb[i]] = 1;
        }
        cout << ans << '\n';
    }
}