#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
string word[11];
int cost[26];
vector <pair<int,char>> v;
map <char,int> priority;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> word[i];
    for(int i = 0; i < n; i++){
        int w = 1;
        for(int j = word[i].size() - 1; j >= 0; j--){
            cost[word[i][j] - 'A'] += w;
            w *= 10;
        }
    }    
    
    for(int i = 0; i < 26; i++) 
        if(cost[i]) 
            v.push_back({cost[i],i+'A'});

    sort(v.rbegin(),v.rend());
    for(int i = 0; i < v.size(); i++) {
        priority[v[i].second] = 9 - i;
    }
    ll sum = 0;
    for(int i = 0; i < n; i++){
        int cnt = 1;
        for(int j = word[i].size() - 1; j >= 0; j--){
            sum += priority[word[i][j]] * cnt;
            cnt *= 10;
        }
    }
    cout << sum << '\n';
}