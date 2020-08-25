#include <iostream>
#include <cmath>
using namespace std;
int n,r,c,num=0;
int board[3000][3000];

//TODO 못함

//z모양으로 숫자 채우기
void putNumInBoard(int row,int col,int &num,int board[3000][3000]){
    for(int i = row; i< row + 2; i++){
        for(int j = col; j < col + 2; j++){
            board[i][j] = num++;
        }
    }
}

int main(){
    
    cin >> n >> r >> c; // 2*n X 2*n의 판에서 (r,c)는 무슨 숫자?
    int MAX = pow(2,n);
    for(int i = 0; i < MAX; i+=2){
        for(int j = 0; j < MAX; j+=2){
            putNumInBoard(i,j,num,board);
        }
    }
    /*for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            cout << board[i][j] <<  ' ';
        }
        cout << '\n';
    }*/
    cout << board[r][c];
}