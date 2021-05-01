#include <bits/stdc++.h>
using namespace std;
int t;
bool cmp(int a,int b){
    return a-b;
}
int main(){
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(),v.end(),cmp);
        for(auto el: v) cout << el << ' ';
        cout << '\n';
    }
}