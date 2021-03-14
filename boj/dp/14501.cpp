//TODO
#include <bits/stdc++.h>
using namespace std;
int d[16][2000], n;
struct consulting{
    int time, price;
};

int dp(int piv,int time,int price,vector<consulting> &v){
    if(piv == n) return 0;
    int & ret = d[time][price];
    if(ret!=-1) return ret;
    if(time - v[piv].time >= 0)
        ret = max(ret,dp(piv+1,time - v[piv].time,price + v[piv].price,v));
    ret = max(ret,dp(piv+1,time,price,v));
    return ret;
};
//i번째일에서 의 금액
int main(){
    vector <consulting> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        int t,c;
        cin >> t >> c;
        v.push_back({t,c});
    }
    memset(d,-1,sizeof(d));
    cout << dp(0,n,0,v);

}