#include <iostream>
using namespace std;
int r,c;
char card[101][101];
char backCard[101][101];
int error[2];
int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> card[i][j];
    for(int i = 0; i < 2; i++) cin >> error[i];

    for(int i = 0; i < r * 2; i++)
        for(int j = 0; j < c; j++)
            backCard[i][j] = backCard[i][c*2-1-j] = card[i][j];

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c*2; j++){
            backCard[i+r][j] = backCard[r-i-1][j];
        }
    }
    if(backCard[error[0]-1][error[1]-1] =='.') 
        backCard[error[0]-1][error[1]-1] = '#';
    else
        backCard[error[0]-1][error[1]-1] = '.';
    for(int i = 0; i < r*2 ; i++){
        cout << backCard[i] <<'\n';
    }
}