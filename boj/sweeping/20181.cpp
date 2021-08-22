//TODO
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, food[100001], l, r, sum, energy;
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> food[i];
    while(l <= r){
        if(sum + food[r] < k) sum += food[r++];
        else{
            sum += food[r];
            energy += sum - k;
            sum -= food[l++];
        }
        cout << "l , r : " << l << ' ' << r << '\n';
        cout << sum << '\n';
    }
    cout << energy << '\n';
}