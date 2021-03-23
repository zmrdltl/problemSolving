#include <bits/stdc++.h>
using namespace std;
using pii = pair <int,int>;
//이동 중 이미 합쳐진 블록은 바로 또 합칠 수 없다
int n, ans;
int board[21][21];
int boardCopy[21][21];
int stat[5];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
//dir = 0 : 상, 1 : 우, 2 : 하, 3 : 좌로 이동
void moveBlock(){
    queue <pii> q; //값,열
    int isCombined[21][21];
    memset(isCombined,0,sizeof(isCombined));
    for(int i = 0; i < n; i++){
        vector <int> v;
        for(int j = 0; j < n; j++){
            if(boardCopy[j][i]) v.push_back((boardCopy[j][i]));
        }

        for(int j = 0; j < v.size(); j++){
            if(j < v.size()-1 && v[j] != 0 && v[j] == v[j+1] ){
                q.push({v[j] + v[j+1],i});
                v[j] = 0, v[j+1] = 0;
                j++;
            }
            if(v[j])
                q.push({v[j],i});
        }
    }
    //q에 다 저장되어 있음
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            boardCopy[i][j] = 0;
        }
    }
    //boardCopy에 바뀐 값 저장
    int rowPivot = 0; //지금 어떤 행 할 차례다 알려주는 용도
    int colPivot = 0; //지금 어떤 열 할 차례다 알려주는 용도
    while(!q.empty()){
        int val = q.front().first;
        int col = q.front().second;
        q.pop();
        if(colPivot != col) {colPivot = col,rowPivot = 0;}
        boardCopy[rowPivot++][col] = val;
    }
}

void copyBoard(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            boardCopy[i][j] = board[i][j];
        }
    }
}

int getMaxBlock(){
    int big = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            big = max(big,boardCopy[i][j]);
    return big;
}

void rotateBoardCopy(){
    int tmp[21][21];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            tmp[i][j] = boardCopy[n-1-j][i];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            boardCopy[i][j] = tmp[i][j];
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    //각 이동 방향은 0,1,2,3으로 표현됨
    //i번째 이동의 이동 방향은 1 2 1 2 1 이런식으로 표현
    //i번째 이동 방향 구하고 이동하기
    
    for(int i = 0; i < 1 << (2 * 5); i++){
        copyBoard();
        int moveStat = i;
        for(int j = 0; j < 5; j++){
            int rotateNum = moveStat % 4;
            moveStat /= 4;
            switch(rotateNum){
                //상우하좌 case 0할필요없음
                case 1:
                rotateBoardCopy();
                break;

                case 2:
                rotateBoardCopy();
                rotateBoardCopy();
                break;

                case 3:
                rotateBoardCopy();
                rotateBoardCopy();
                rotateBoardCopy();
                break;
            }
            moveBlock();
        }
        ans = max(ans,getMaxBlock());

    }
    cout << ans <<'\n';
}