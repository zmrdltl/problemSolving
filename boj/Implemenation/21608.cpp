#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n, board[21][21], likeBoard[21][21];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
vector <int> info[500];
vector <pii> possibleSeats;

void findMaxEmptyBlock(int studentNum){
    sort(possibleSeats.begin(),possibleSeats.end());
    vector <int> emptyCnt;
    int maxCnt = 0;
    for(auto c : possibleSeats){
        int cnt = 0;
        for(int i = 0; i < 4; i++){
            int nx = c.first + dx[i];
            int ny = c.second + dy[i];
            if(1 > nx || nx > n || 1 > ny || ny > n) continue;
            if(board[nx][ny]) continue;
            cnt++;
        }
        maxCnt = max(maxCnt,cnt);
        emptyCnt.push_back(cnt);
    }

    for(int i = 0; i < emptyCnt.size(); i++){
        if(emptyCnt[i] == maxCnt){
            board[possibleSeats[i].first][possibleSeats[i].second] = studentNum;
            return;
        }
    }
}

void findLikeSquare(int studentNum){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int num = 0; num < info[studentNum].size(); num++){
                if(board[i][j] != info[studentNum][num]) continue;
                for(int dir = 0; dir < 4; dir++){
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(1 > nx || nx > n || 1 > ny || ny > n) continue;
                    if(board[nx][ny]) continue;
                    likeBoard[nx][ny]++;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cnt = max(cnt,likeBoard[i][j]);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(cnt == likeBoard[i][j] && !board[i][j]){
                possibleSeats.push_back({i,j});
            }
        }
    }
}

int getSatisfied(){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int student = board[i][j];
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(1 > nx || nx > n || 1 > ny || ny > n) continue;
                for(int num = 0; num < info[student].size(); num++){
                    if(info[student][num] != board[nx][ny]) continue;
                    cnt++;
                }
            }
            sum += pow(10,cnt-1);
        }
    }
    return sum;
}

int main(){
    cin >> n;
    for(int i = 0; i < n*n; i++){
        possibleSeats.clear();
        memset(likeBoard,0,sizeof(likeBoard));
        int x, like;
        cin >> x;
        for(int i = 0; i < 4; i++) {
            cin >> like;
            info[x].push_back(like);
        }
        findLikeSquare(x);
        findMaxEmptyBlock(x);
    }
    cout << getSatisfied();
}