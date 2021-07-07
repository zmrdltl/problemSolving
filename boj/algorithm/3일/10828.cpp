#include <bits/stdc++.h>
using namespace std;
int n;
stack <int> st;
int main(){
    cin >> n;
    while(n--){
        string op;
        cin >> op;
        if(op == "push"){
            int x;
            cin >> x;
            st.push(x);
        }
        else if(op == "pop"){
            if(st.size()) cout << st.top() << '\n', st.pop();
            else cout << -1 << '\n';
        }
        else if(op == "size") cout << st.size() << '\n';
        else if(op == "empty") cout << st.empty() << '\n';
        else if(op == "top"){
            if(st.size()) cout << st.top() << '\n';
            else cout << -1 << '\n';
        }
    }
}