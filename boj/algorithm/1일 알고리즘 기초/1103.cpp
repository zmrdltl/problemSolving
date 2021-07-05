#include <bits/stdc++.h>
using namespace std;
using tpii = tuple<int,int,int>; //x,y,¿òÁ÷ÀÎ È½¼ö
int n,m;
//»ó, ÇÏ, ÁÂ, ¿ì
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int cycleCk[51][51];
char board[51][51];
int coinXPos, coinYPos;
int moved, curX;
queue <tpii> q;

int getX(){
    moved++;
    return board[coinXPos][coinYPos] - '0';
}

int operationTwo(){
    moved++;
    
    for(int i = 0; i < 4; i++){
        int num = board[coinXPos][coinYPos] - '0';
        int nx = coinXPos + num * dx[i];
        int ny = coinYPos + num * dy[i];
        if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
        q.push({nx,ny,dir});
    }
}

void operationThree(){
    moved++;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    q.push({0,0,0});
    while(1){
        if(board[coinXPos][coinYPos] == '1'){
            curX = getX();
        }
        else if(board[coinXPos][coinYPos] == '2'){

        }
        else if(board[coinXPos][coinYPos] == '3'){

        }
        else{
            break;
        }
    }
    cout << moved << '\n';
}