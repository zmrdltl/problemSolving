#include <bits/stdc++.h>
using namespace std;
int n;
map <string,int> m;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        m[s] = 1;
    }
    cout << m.size();
}