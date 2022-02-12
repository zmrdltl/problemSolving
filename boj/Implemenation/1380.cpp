#include <bits/stdc++.h>
using namespace std;

int main(){
    for(int t = 1; ;t++){
        int n;
        cin >> n;
        if(!n) break;

        vector <string> name;
        unordered_map <int,int> m;
        string s;

        cin.ignore();

        for(int i = 1; i <= n; i++) {
            getline(cin,s);
            m[i] = 2;
            name.push_back(s);
        }
        for(int i = 0; i < 2 * n - 1; i++){
            int a; char c;
            cin >> a >> c;
            m[a]--;
        }
        for(auto el : m){
            if(el.second) cout << t << ' ' << name[el.first-1] << '\n';
        }
    }
}