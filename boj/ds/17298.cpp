#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000001],ans[1000001];
stack <int> s;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        while(!s.empty() && a[s.top()] < a[i]){
            ans[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        ans[s.top()] = -1;
        s.pop();
    }
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
}