#include <bits/stdc++.h>
using namespace std;
int n;
vector <string> v(1001);
map <string,int> m;

int main(){
    while(1){
        cin >> n;
        if(!n) break;
        v.clear(), m.clear();
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            string tmp;
            for(int j = 0; j < v[i].size(); j++){
                if('A' <= v[i][j] && v[i][j] <= 'Z') tmp += v[i][j] -'A' +'a';
                else tmp += v[i][j];
            }
            m[tmp] = i;
        }
        cout << v[m.begin() -> second] << '\n';
    }
}