#include <iostream>
#include <vector>
#include <string>
#include <map>
#define ll long long 
using namespace std;
map<string, ll> familyInfo;
string ans;
ll tmp, n, m;
vector<vector<string>> v(3);
string establisher;
int main(void) {
    
    cin >> n >> m >> establisher;
    familyInfo[establisher] = 1ll << 50;
    string name;
    for (int i = 0; i < n; i++) {
        cin >> name, v[0].push_back(name); //자식
        cin >> name, v[1].push_back(name); //부모1
        cin >> name, v[2].push_back(name); //부모2
    }

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            familyInfo[v[0][j]] = (familyInfo[v[1][j]] + familyInfo[v[2][j]]) / 2;
        }
    }
    for(auto p : familyInfo) cout << p.first << ' ' << p.second << '\n';
    for (int i = 0; i < m; i++) {
        cin >> name;
        if(familyInfo[name] > tmp) tmp = familyInfo[name], ans = name;
    }

    cout << ans << endl;
}