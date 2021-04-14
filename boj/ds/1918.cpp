#include <bits/stdc++.h>
using namespace std;
string str, ans;
stack <char> op;
int main() {
    cin >> str;
    
    for (int i = 0; i < str.size(); i++) {
        if ('A' <= str[i] && str[i] <= 'Z') { ans += str[i]; continue; }

        if(str[i] == '(') { op.push(str[i]); continue; }

        if(str[i] == ')'){
            while(op.top()!='(') 
                ans += op.top(), op.pop(); 
            op.pop();
            continue;
        }
        if(str[i] == '*' || str[i] == '/'){
            while(!op.empty() && (op.top() == '*' || op.top() == '/'))
                ans += op.top(), op.pop();
        }
        else{
            while(!op.empty() && op.top() != '(')
                ans += op.top(), op.pop(); 
        }
        op.push(str[i]);
    }
 
    while (!op.empty()) 
        ans += op.top(), op.pop();
    cout << ans <<'\n';    
}

