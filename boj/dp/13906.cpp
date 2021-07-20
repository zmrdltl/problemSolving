#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e+9 + 7;
string s;
int alpha[26];
int d[1001]; //i부터 끝까지 만들 수 있는 대문자의 수
int main(){
    cin >> s;
    for(int i = s.size(); i >= 0; i--){
        memset(alpha,0,sizeof(alpha));
        d[i] = 1;
        for(int j = i; j < s.size(); j++){
            if(++alpha[s[j] -'a'] == 3){
                d[i] = (d[i] + d[j+1]) % MOD;
            }
        }
    }
    cout << (d[0] + MOD - 1) % MOD;
}