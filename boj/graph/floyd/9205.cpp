#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

bool canGo(int distance){
    return distance <= 1000 ? true : false;
}

void storeDistances(int n, vector <pair<int,int>> &map, int checkPath[105][105]){
    for(int i = 0; i < n + 2; i++){
        for(int j = i + 1; j < n + 2; j++){
            int distance = abs(map[i].first - map[j].first) + abs(map[i].second - map[j].second);
            checkPath[j][i] = checkPath[i][j] = canGo(distance);
        }
    }
}

void floydWarshell(int n, int checkPath[105][105]){
    for(int k = 0; k < n + 2; k++)
            for(int i = 0; i < n + 2; i++)
                for(int j = 0; j < n + 2; j++)
                    if(checkPath[i][k]&&checkPath[k][j]) checkPath[i][j] = 1;
}

int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;

        vector <pair<int,int>> map(n+2,{0,0});
        int checkPath[105][105];
        memset(checkPath,0,sizeof(checkPath));

        for(int i = 0; i < n + 2; i++) cin >> map[i].first >> map[i].second;
        
        storeDistances(n, map, checkPath);
        floydWarshell(n, checkPath);

        if(checkPath[0][n+1]) cout << "happy\n";
        else cout << "sad\n";
    }
}