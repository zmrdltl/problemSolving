#include <bits/stdc++.h>
using namespace std;
string s, ans;
stack <char> st;
int main(){
    getline(cin,s);
    int flag = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != '<') st.push(s[i]);
        if(s[i] == '<') {
            while(!st.empty()) ans += st.top(), st.pop();
            st.push(s[i]);
            flag = 1;
        }
        else if(s[i] == '>'){
            string tmp;
            while(!st.empty()) tmp += st.top(),st.pop();
            if(flag) {
                flag = 0;
                reverse(tmp.begin(),tmp.end());
                ans += tmp;
            }
        }
        else if(s[i] == ' ' || i == s.size() - 1){
            if(!flag){
                int f = 0;
                string tmp;
                while(!st.empty()){
                    if(st.top()!= ' ') tmp += st.top();
                    else f = 1;
                    st.pop();
                }
                ans += tmp;
                if(f) ans += ' ';
            }    
        }
    }
    cout << ans << '\n';
}