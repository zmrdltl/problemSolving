#include <bits/stdc++.h>
using namespace std;

string brackets; 
stack <char> st;
int ans, piv = 1, valid = 1;

int main(){
	cin >> brackets;
	for(int i = 0; i < brackets.size(); i++){
        if(brackets[i] == '('){
            piv *= 2;
            st.push('(');
        }
        if(brackets[i] == '['){
            piv *= 3;
            st.push('[');
        }
        if(brackets[i] == ')'){
            if(!st.size() || st.top() != '(') { valid = 0; break; }
            if(brackets[i-1] == '(') ans += piv;
            piv /= 2;
            st.pop();
        }
        if(brackets[i] == ']'){
            if(!st.size() || st.top() != '[') { valid = 0; break; }
            if(brackets[i-1] == '[') ans += piv;
            piv /= 3;
            st.pop();
        }
    }
    if(!valid || st.size()) cout << 0;
    else cout << ans;
}