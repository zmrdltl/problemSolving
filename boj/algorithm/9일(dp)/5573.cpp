#include <bits/stdc++.h>
using namespace std;
int h,w,n,r,c;
int board[1001][1001], d[1001][1001]; //i, j�� �湮�ϴ� Ƚ��
int main(){
    cin >> h >> w >> n;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> board[i][j];
        }
    }
    d[0][0] = n;
    for(int i = 0; i < h; i++){
        if(r == h || c == w) break; //�����ÿ��� ����
        for(int j = 0; j < w; j++){
            if(d[i][j] % 2 == 0) board[i][j] = 1 - board[i][j]; //¦����°���� �� ����
            if(i + 1 < h) d[i+1][j] += d[i][j]/2;
            if(j + 1 < w) d[i][j+1] += d[i][j]/2;
            if(d[i][j] % 2 == 1){
                if(!board[i][j] && i+1 < h) d[i+1][j]++; //���ڰ� ���� �ƾ��� �����U
                if(board[i][j] && j+1 < w) d[i][j+1]++; //���ڰ� �Ƹ� ���ξ��� �Ʒ���
            }
            if(r == i && c == j){
                if(board[i][j]) c++;
                else r++;
            }
        }
    }
    cout << r + 1 << ' ' << c + 1;
}