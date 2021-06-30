#include <bits/stdc++.h>
using namespace std;
using tsiii = tuple <string, int, int, int>;
int n;
vector <tsiii> v;

bool cmp(tsiii &a, tsiii &b){
    int ad = get<1>(a);
    int am = get<2>(a);
    int ay = get<3>(a);

    int bd = get<1>(b);
    int bm = get<2>(b);
    int by = get<3>(b);

    if(ay == by){
        if(am == bm) return ad > bd;
        return am > bm;
    }
    return ay > by;
}

int main(){
    cin >> n;
    while(n--){
        string s;
        int day, month, year;
        cin >> s >> day >> month >> year;
        v.push_back({s,day,month,year});
    }
    sort(v.begin(),v.end(),cmp);
    tsiii young = v[0], old = v[v.size()-1];
    cout << get<0>(young) << '\n' << get<0>(old);
}