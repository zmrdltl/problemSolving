#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, a[100001];
int main(){
    while(1){
        stack <ll> st;
        ll ans = 0, left = 0;
        cin >> n;
        if(!n) break;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++){

            while(st.size() && a[st.top()] > a[i]){
                ll height = a[st.top()];
                st.pop();
                ll width = i;
                if(!st.empty()){
                    width = (i - st.top() - 1);
                }
                ans = max(ans, height * width);
            }
            st.push(i);
        }

        while(st.size()){
            ll height = a[st.top()];
            st.pop();
            ll width = n;
            if(!st.empty()){
                width = n - st.top() - 1;
            }
            ans = max(ans, height * width);
        }


        cout << ans << '\n';
    }
}
