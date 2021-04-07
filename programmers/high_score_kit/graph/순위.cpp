#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int gameInfo[101][101];
    memset(gameInfo,0,sizeof(gameInfo));

    for(auto &r : results)
        gameInfo[r[0]][r[1]] = 1;

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(gameInfo[i][k] && gameInfo[k][j])
                    gameInfo[i][j] = 1;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++)
            if(gameInfo[i][j] || gameInfo[j][i])
                cnt++;
        if(cnt == n-1)
            answer++;
    }

    return answer;
}