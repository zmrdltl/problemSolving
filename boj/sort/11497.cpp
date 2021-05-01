#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
    cin >> t;
    while(t--){
        int n,ans=0;
        cin >> n;
        vector <int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(),v.end());
        for(int i = 0; i < v.size()-2; i++){
            ans = max(ans,abs(v[i]-v[i+2]));
        }
        cout << ans << '\n';
    }
}