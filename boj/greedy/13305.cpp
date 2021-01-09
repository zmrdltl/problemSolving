#include <iostream>
#define ll long long
using namespace std;
ll cityDistance[100001];
ll oilCost[100001];
ll n;
int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++) cin >> cityDistance[i];
    for(int i = 0; i < n; i++) cin >> oilCost[i];
    
    ll pivot = oilCost[0];
    ll ans = 0;
    ll cnt = 0;

    for(int i = 0; i < n-1; i++){
        cnt += cityDistance[i];
        if(pivot > oilCost[i+1]){
            ans += pivot * cnt;
            pivot = oilCost[i+1];
            cnt = 0;
        }
    }
    ans += pivot * cnt; //다 pivot보다 비싸면 더해줘야한다.
    cout << ans << '\n';
}