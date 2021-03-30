#include <bits/stdc++.h>
using namespace std;
int n,k;
string s, tmp;
vector <int> a;
int main(){
    cin >> n >> k;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        tmp+=s[i];
        if(s[i]==',' || i==s.size()-1){
            a.push_back(stoi(tmp));
            tmp ="";
        }
    }
    while(k--){
        vector <int> b;
        for(int i = 0; i < a.size() - 1; i++){
            b.push_back(a[i+1]-a[i]);
        }
        a = b;
    }
    for(int i = 0; i < a.size(); i++) {
        cout << a[i];
        if(i != a.size()-1) cout << ',';
    }
}