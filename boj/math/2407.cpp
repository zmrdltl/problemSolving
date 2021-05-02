#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, ans;
string comb[101][101];

string numToString(string a, string b){
    ll sum = 0;
    string ret;
    while(a.size() || b.size() || sum){
        if(a.size()){
            sum += a.back() - '0';
            a.pop_back();
        }
        if(b.size()){
            sum += b.back() - '0';
            b.pop_back();
        }
        ret.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

string combination(int n, int m){
    if(n == m || m == 0) return "1";
    string &ret = comb[n][m];
    if(ret != "") return ret;
    ret = numToString(combination(n-1,m-1), combination(n-1,m));
    return ret;
}

int main(){
    cin >> n >> m;
    cout << combination(n,m);
}