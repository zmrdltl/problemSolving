#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n;
deque <int> dq;
int main(){
    fastio;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(s == "push") {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if(s=="pop"){
            if(dq.empty()) cout << -1 <<'\n';
            else {
                cout << dq.front() <<'\n';
                dq.pop_front();
            }
        }
        else if(s=="size")
            cout << dq.size() <<'\n';
        else if(s=="empty")
            cout << dq.empty() << '\n';
        else if(s == "front"){
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        }
        else if(s == "back"){
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }
    }
}