#include <bits/stdc++.h>
using namespace std;
int sudoku[10][10], rowCk[10][10], colCk[10][10], squareCk[100][10];
void backtracking(int cnt){
    int row = cnt / 9;
    int col = cnt % 9;
    
    if(cnt == 81) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
    if(!sudoku[row][col]){
        for(int i = 1; i <= 9; i++){
            if(rowCk[row][i] || colCk[col][i] || squareCk[(row / 3) * 3 + (col / 3)][i]) continue;
            rowCk[row][i] = colCk[col][i] = squareCk[(row / 3) * 3 + (col / 3)][i] = 1;
            sudoku[row][col] = i;
            backtracking(cnt + 1);
            sudoku[row][col] = 0;
            rowCk[row][i] = colCk[col][i] = squareCk[(row / 3) * 3 + (col / 3)][i] = 0;
        }
    }
    else backtracking(cnt + 1);
}

int main(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j]){
                int num = sudoku[i][j];
                rowCk[i][num] = colCk[j][num] = squareCk[(i / 3) * 3 + (j / 3)][num] = 1;
            }
        }
    }
    backtracking(0);
}