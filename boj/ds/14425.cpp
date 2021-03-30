#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
map <string,int> dict;

int main(){
    cin >> n >> m;
    while(n--){
        string s;
        cin >> s;
        dict[s] = -1;
    }
    while(m--){
        string s;
        cin >> s;
        if(dict[s]==-1)ans++;
    }
    cout << ans <<'\n';
}