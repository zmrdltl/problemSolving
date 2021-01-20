#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;
    cin >> n;
    while(n--){
        string word;
        stack <char> s;
        cin >> word;
        for(int i = 0; i < word.size(); i++){
            if(!s.size()) s.push(word[i]);
            else {
                if(s.top()!=word[i]) s.push(word[i]);
                else s.pop();
            }
        }
        if(s.empty()) ans++;
    }
    cout << ans <<'\n';
}