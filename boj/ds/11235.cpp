#include <bits/stdc++.h>
using namespace std;
int n;
map <string,int> m;
int maxPoll;
int main(){
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        m[s]++;
    }
    for(auto a : m) maxPoll = max(maxPoll,a.second);
    for(auto a : m)
        if(a.second==maxPoll) 
            cout << a.first <<'\n';
}