#include <bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool isConvergence(vector <ll> num){
    if(num[0] == num[1] && num[1] == num[2] && num[2] == num[3]) return true;
    return false;
}

vector<ll> getNextSequence(vector <ll> num){
    vector <ll> tmp(4);
    tmp[0] = abs(num[0] - num[1]);
    tmp[1] = abs(num[1] - num[2]);
    tmp[2] = abs(num[2] - num[3]);
    tmp[3] = abs(num[3] - num[0]);
    return tmp;
}

int main(){
    fastio;
    while(1){
        int cnt = 0;
        vector <ll> num(4);
        for(int i = 0; i < 4; i++) cin >> num[i];
        if(!num[0] && !num[1] && !num[2] && !num[3]) break;
        while(!isConvergence(num)){
            cnt++;
            num = getNextSequence(num);
        }
        cout << cnt << '\n';
    }
}