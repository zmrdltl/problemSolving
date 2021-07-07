#include <bits/stdc++.h>
using namespace std;
int n;
queue <int> q;
int main(){
    cin >> n;
    while(n--){
        string op;
        cin >> op;
        if(op == "push"){
            int x;
            cin >> x;
            q.push(x);
        }
        else if(op == "pop"){
            if(q.size()) cout << q.front(), q.pop();
            else cout << -1;
        }
        else if(op == "size"){
            cout << q.size();
        }
        else if(op == "empty"){
            cout << q.empty();
        }
        else if(op == "front"){
            if(q.size()) cout << q.front();
            else cout << -1;
        }
        else if(op == "back"){
            if(q.size()) cout << q.back();
            else cout << -1;
        }
        if(op!="push")cout << '\n';
    }
}