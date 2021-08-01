#include <bits/stdc++.h>
using namespace std;
using pci = pair<char,int>;
int cnt = 0;
int main(){
    while(1){
        cnt++;
        string s, filtered="";
        int isFiltered[2001] ={0};
        stack <pci> st;
        cin >> s;
        if(s[0] == '-') break;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '{')
                st.push({s[i],i});
            else {
                if(st.size() && st.top().first == '{'){
                    isFiltered[st.top().second] = 1;
                    isFiltered[i] = 1;
                    st.pop();
                }
            }
        }
        int leftBracket = 0, rightBracket = 0;
        for(int i = 0; i < s.size(); i++){
            if(!isFiltered[i]) {
                filtered += s[i];
                if(s[i] == '{') leftBracket++;
                else rightBracket++;
            }
        }
        if(leftBracket % 2 && rightBracket % 2){
            cout << cnt << ". " << leftBracket / 2 + 1 + rightBracket / 2 + 1 << '\n';
        }
        else{
            cout << cnt << ". " << leftBracket / 2 + rightBracket / 2 << '\n';
        }
    }
}