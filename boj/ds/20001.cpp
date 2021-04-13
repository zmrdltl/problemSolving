#include <bits/stdc++.h>
using namespace std;
queue <string> q;
string s;
int main(){
    while(1){
        getline(cin, s);
        if(s == "고무오리 디버깅 끝") break;
        else if(s == "문제") q.push(s);
        else if(s == "고무오리"){
            if(q.empty()) {
                q.push("문제");
                q.push("문제");
            }
            else q.pop();
        } 
    }
   
    if(!q.empty()) cout << "힝구";
    else cout << "고무오리야 사랑해";
}