#include <bits/stdc++.h>
using namespace std;
int n;
vector <string> s;
map <string,int> m;
int main(){
    cin >> n;
    while(n--){
        string name, stat;
        cin >> name >> stat;
        if(stat == "leave") m[name] = 0;
        else m[name] = 1;
    }
    for(auto el : m){
        if(el.second) s.push_back(el.first);
    }
    sort(s.rbegin(),s.rend());
    for(auto el : s) cout << el << '\n';
}