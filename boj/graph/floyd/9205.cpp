#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
int t,n;

bool canGo(int distance){
    return distance <= 1000 ? true : false;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        vector <pair<int,int>> map(n+2,{0,0});
        int dist[105][105];
        memset(dist,0,sizeof(dist));
        for(int i = 0; i < n + 2; i++){
            cin >> map[i].first >> map[i].second;
        }

        for(int i = 0; i < n + 2; i++){
            for(int j = i + 1; j < n + 2; j++){
                int distance = abs(map[i].first - map[j].first) + abs(map[i].second - map[j].second);
                if(canGo(distance)) {
                    dist[i][j] = 1;
                    dist[j][i] = 1;
                }
            }
        }

        for(int k = 0; k < n + 2; k++){
            for(int i = 0; i < n+2; i++){
                for(int j = 0; j < n+2; j++){
                    if(dist[i][k] == 1&&dist[k][j] == 1) {dist[i][j] = 1;dist[j][i] = 1;}
                }
            }
        }

        if(dist[0][n+1]) cout << "happy\n";
        else cout << "sad\n";
    }
}