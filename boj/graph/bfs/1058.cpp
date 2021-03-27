#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int,int>;
int n, ans;
int friendGraph[51][51];
int dist[51][51];
int main(){
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dist[i][j] = INF;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == 'Y') friendGraph[i][j] = 1, dist[i][j] = 1;
            else friendGraph[i][j] = 0;
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(dist[i][j] <= 2 ) cnt++;
        }
        ans = max(ans,cnt);
    }
    
    cout << ans <<'\n';

}