#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll g;
bool flag;
vector <ll> square;
int main(){
    cin >> g;
    for(ll i = 1; i <= 100000; i++) square.push_back(i * i);
    for(ll w = 1; w <= 100000; w++){
        auto x = lower_bound(square.begin(), square.end(), w * w - g);
        if(*x == w * w - g){
            flag = true;
            cout << w << '\n';
        }
    }
    if(flag == false) cout << -1;
}