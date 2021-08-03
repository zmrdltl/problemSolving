#include <bits/stdc++.h>
using namespace std;
int t, side;
char board[101][101];
vector <int> squares;

void rotateClockwise(){
    char tmp[101][101];
    for(int i = 0; i < side; i++){
        for(int j = 0; j < side; j++){
            tmp[i][j] = board[side-j-1][i];
        }
    }
    for(int i = 0; i < side; i++){
        for(int j = 0; j < side; j++){
            board[i][j] = tmp[i][j];
        }
    }
}

int main(){
    for(int i = 1; i <= 100; i++) squares.push_back(i*i);

    cin >> t;
    while(t--){
        memset(board,'*',sizeof(board));
        string s;
        cin >> s;

        for(auto sq : squares){
            if(sq >= s.size()) {side = sqrt(sq); break;}
        }

        int piv = 0;
        for(int i = 0; i < side; i++){
            for(int j = 0; j < side; j++){
                if(piv < s.size()) board[i][j] = s[piv++];
                else board[i][j] = '*';
            }
        }
        
        rotateClockwise();

        for(int i = 0; i < side; i++)
            for(int j = 0; j < side; j++)
                if(board[i][j] !='*')
                    cout << board[i][j];

        cout << '\n';
    }
}