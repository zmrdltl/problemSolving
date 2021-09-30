#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, m;
int main(){
    fastio;
    while(1){
        cin >> n >> m;
        if(!n && !m) break;
        vector <int> secondRankPlayer, ans;
        map<int, int> playerScoreMap; //선수번호, 점수
        int first = 0, second = 0;
        for(int i = 0, x; i < n * m; i++){
            cin >> x;
            playerScoreMap[x]++;
        }
        for(auto el : playerScoreMap){
            first = max(first, el.second);
        }
        for(auto el : playerScoreMap){
            if(el.second == first) continue;
            second = max(second, el.second);
        }
        for(auto el : playerScoreMap){
            if(el.second == second) cout << el.first << ' ';
        }
        cout << '\n';
    }
}