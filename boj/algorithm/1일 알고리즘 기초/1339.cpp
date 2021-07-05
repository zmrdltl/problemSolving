#include <bits/stdc++.h>
using namespace std;
using pic = pair<int,char>;
vector <pic> v;
map <char,int> dictPerAlpha;
string words[11];
int costPerAlpha[26];
int n, ans;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> words[i];
        int cost = 1;
        for(int j = words[i].size() - 1; j >= 0 ; j--){
            costPerAlpha[words[i][j] - 'A'] += cost;
            cost *= 10;
        }
    }
    for(int i = 0; i < 26; i++){
        if(costPerAlpha[i]){
            v.push_back({costPerAlpha[i], i + 'A'});
        }
    }
    sort(v.rbegin(),v.rend());
    int cnt = 9;
    for(auto el : v){
        dictPerAlpha[el.second] = cnt--;
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        string tmp = "";
        for(int j = 0; j < words[i].size(); j++){
            tmp += to_string(dictPerAlpha[words[i][j]]);
        }
        sum += stoi(tmp);
    }
    cout << sum << '\n';
}