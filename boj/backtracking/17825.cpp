#include <bits/stdc++.h>
using namespace std;
// {점수, 각 주사위 1나왔을 때 위치,2,3,4,5}
const int table[33][6]={
    //0 ~ 4
    {0 , 1 , 2 , 3 , 4 , 5 },
    {2 , 2 , 3 , 4 , 5 , 6 },
    {4 , 3 , 4 , 5 , 6 , 7 },
    {6 , 4 , 5 , 6 , 7 , 8 },
    {8 , 5 , 6 , 7 , 8 , 9 },

    //5 ~ 9
    {10, 23, 24, 25, 28, 29},
    {12, 7 , 8 , 9 , 10, 11},
    {14, 8 , 9 , 10, 11, 12},
    {16, 9 , 10, 11, 12, 13},
    {18, 10, 11, 12, 13, 14},

    //10 ~ 14
    {20, 26, 27, 28, 29, 30},
    {22, 12, 13, 14, 15, 16},
    {24, 13, 14, 15, 16, 17},
    {26, 14, 15, 16, 17, 18},
    {28, 15, 16, 17, 18, 19},

    //15 ~ 19
    {30, 20, 21, 22, 28, 29},
    {32, 17, 18, 19, 31, 32},
    {34, 18, 19, 31, 32, 32},
    {36, 19, 31, 32, 32, 32},
    {38, 31, 32, 32, 32, 32},

    //20 ~ 24
    {28, 21, 22, 28, 29, 30},
    {27, 22, 28, 29, 30, 31},
    {26, 28, 29, 30, 31, 32},
    {13, 24, 25, 28, 29, 30},
    {16, 25, 28, 29, 30, 31},

    //25 ~ 29
    {19, 28, 29, 30, 31, 32},
    {22, 27, 28, 29, 30, 31},
    {24, 28, 29, 30, 31, 32},
    {25, 29, 30, 31, 32, 32},
    {30, 30, 31, 32, 32, 32},

    //30 ~ 32
    {35, 31, 32, 32, 32, 32},
    {40, 32, 32, 32, 32, 32},
    {0 , 32, 32, 32, 32, 32},
};

int dice[10], ans;

int getScore(int state){
    int ret = 0;
    bool visited[33] = {false, };
    int pos[4] = {0 ,}; //각 말의 위치 저장
    for(int turn = 0; turn < 10; turn++){
        int move = dice[turn];
        int horse = (state >> (turn * 2)) & 0x03; //state마지막 2bit이 대입됨
        int &curPos = pos[horse];
        int nextPos = table[curPos][move];
        int score = table[nextPos][0];
        if(visited[nextPos] && nextPos != 32) return -1;
        ret += score;
        visited[curPos] = false;
        visited[nextPos] = true;
        curPos = nextPos;
    }
    return ret;
}
int main(){
    for(int i = 0; i < 10; i++) cin >> dice[i];

    for(int state = 0; state < 1<<20; state++){
        int score = getScore(state);
        ans = max(ans,score);
    } 
    cout << ans <<'\n';
}