#include <bits/stdc++.h>
using namespace std;
int chessboard[8][8];
int main(){
    string king,stone;
    int moveCount;
    cin >> king >> stone >> moveCount;
    string currentKingPosition = king;
    while(moveCount--){
        string moveDirection;
        char row = currentKingPosition[1];
        char column = currentKingPosition[0];
        cin >> moveDirection;
        if(moveDirection == "R"){
            if(column - '0' + 1 <= 8)
                column = (column - '0' + 1 ) + 'A';
        }
        currentKingPosition = column + row;
        cout << currentKingPosition << '\n';
      
    }
}