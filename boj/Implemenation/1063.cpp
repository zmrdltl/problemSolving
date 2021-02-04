#include <bits/stdc++.h>
using namespace std;
int chessboard[8][8];
int main(){
    string king,stone;
    int moveCount;
    cin >> king >> stone >> moveCount;
    string currentKing = king;
    string currentStone = stone;
    while(moveCount--){
        string moveDirection;
        char kingRow = currentKing[1];
        char kingColumn = currentKing[0];

        char stoneRow = currentStone[1];
        char stoneColumn = currentStone[0];

        cin >> moveDirection;
        if(moveDirection == "R"){
            int nextKingColumn = kingColumn - 'A' + 1;
            if(nextKingColumn >= 8) continue;
            if(nextKingColumn + 'A' == stoneColumn && kingRow == stoneRow){
                if(nextKingColumn + 1 >= 8) continue;
                stoneColumn = nextKingColumn + 1 + 'A';
            }
            kingColumn = nextKingColumn + 'A';
        }

        else if(moveDirection=="L"){
            int nextKingColumn = kingColumn - 'A' - 1;
            if(nextKingColumn < 0) continue;
            if(nextKingColumn + 'A' == stoneColumn && kingRow == stoneRow){
                if(nextKingColumn - 1 < 0) continue;
                stoneColumn = nextKingColumn - 1 + 'A';
            }
            kingColumn = nextKingColumn + 'A';
        }

        else if(moveDirection=="B"){
            int nextKingRow = kingRow - '0' - 1;
            if(nextKingRow < 1) continue;
            if(nextKingRow + '0' == stoneRow && kingColumn == stoneColumn){
                if(nextKingRow - 1 < 1) continue;
                stoneRow = nextKingRow - 1 + '0';
            }
            kingRow = nextKingRow + '0';
        }

        else if(moveDirection=="T"){
            int nextKingRow = kingRow - '0' + 1;
            if(nextKingRow > 8) continue;
            if(nextKingRow + '0' == stoneRow && kingColumn == stoneColumn){
                if(nextKingRow + 1 > 8) continue;
                stoneRow = nextKingRow + 1 + '0';
            }
            kingRow = nextKingRow + '0';
        }

        else if(moveDirection=="RT"){
            int nextKingRow = kingRow - '0' + 1;
            int nextKingColumn = kingColumn - 'A' + 1;

            if(nextKingRow > 8 || nextKingColumn >= 8) continue;

            if(nextKingRow + '0' == stoneRow && nextKingColumn + 'A' == stoneColumn){
                if(nextKingRow + 1 > 8 || nextKingColumn + 1 >= 8) continue;
                stoneRow = nextKingRow + 1 + '0';
                stoneColumn = nextKingColumn + 1 + 'A';
            }
            kingRow = nextKingRow + '0';
            kingColumn = nextKingColumn + 'A';
        }

        else if(moveDirection=="LT"){
            int nextKingRow = kingRow - '0' + 1;
            int nextKingColumn = kingColumn - 'A' - 1;

            if(nextKingRow > 8 || nextKingColumn < 0) continue;
            if(nextKingRow + '0' == stoneRow && nextKingColumn + 'A' == stoneColumn){
                if(nextKingRow + 1 > 8 || nextKingColumn - 1 < 0) continue;
                stoneRow = nextKingRow + 1 + '0';
                stoneColumn = nextKingColumn -1 + 'A';
            }
            kingRow = nextKingRow + '0';
            kingColumn = nextKingColumn + 'A';
        }

        else if(moveDirection == "RB"){
            int nextKingRow = kingRow - '0' - 1;
            int nextKingColumn = kingColumn - 'A' + 1;
            if(nextKingRow < 1 || nextKingColumn >= 8) continue;
            if(nextKingRow + '0' == stoneRow && nextKingColumn + 'A' == stoneColumn){
                if(nextKingRow - 1 < 1 || nextKingColumn + 1 >= 8) continue;
                stoneRow = nextKingRow - 1 + '0';
                stoneColumn = nextKingColumn + 1 + 'A';
            }
            kingRow = nextKingRow + '0';
            kingColumn = nextKingColumn + 'A';
        }

        else if(moveDirection == "LB"){
            int nextKingRow = kingRow - '0' - 1;
            int nextKingColumn = kingColumn - 'A' - 1;
            if(nextKingRow < 1 || nextKingColumn < 0) continue;
            if(nextKingRow + '0' == stoneRow && nextKingColumn + 'A' == stoneColumn){
                if(nextKingRow - 1 < 1 || nextKingColumn - 1 < 0) continue;
                stoneRow = nextKingRow - 1 + '0';
                stoneColumn = nextKingColumn - 1 + 'A';
            }
            kingRow = nextKingRow + '0';
            kingColumn = nextKingColumn + 'A';
        }

        string tmp = "";
        tmp += kingColumn;
        tmp += kingRow;
        currentKing = tmp;
        tmp = "";

        tmp += stoneColumn;
        tmp += stoneRow;
        currentStone = tmp;

    }
    cout << currentKing << '\n' << currentStone << '\n';
}