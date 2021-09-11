#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            board[i][j] = board[i - 1][j] + board[i][j - 1] - board [i - 1][j - 1] + A[i][j];
        }
    }
    for(auto s : skill){
        int num = s[5];
        if(s[0] == 1){
            num *= -1;
        }
        for(int i = s[1]; i <= s[3]; i++){
            for(int j = s[2]; j <= s[4]; j++){
                board[i][j] += num;
            }
        }
    }
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] >= 1) answer++;
        }
    }
    return answer;
}

 
int A[301][301], DP[301][301];
 
int main(void)
{
    int N, M, i, j;
    
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= M; j++) {
            scanf("%d", &A[i][j]);
        }
    }
 
    // (1,1)부터 (i,j)까지의 누적합
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= M; j++) {
            DP[i][j] = DP[i - 1][j] + DP[i][j - 1] - DP [i - 1][j - 1] + A[i][j];
        }
    }
 
    int K, x, y;
    scanf("%d", &K);
    while (K--) {
        scanf("%d %d %d %d", &i, &j, &x, &y);
        printf("%d\n", DP[x][y] - DP[x][j - 1] - DP[i - 1][y] + DP[i - 1][j - 1]);
    }
 
    return 0;
}

