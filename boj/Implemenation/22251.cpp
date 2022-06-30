#include <bits/stdc++.h>
using namespace std;
string startFloor, zeroCnt;
int display, bitNum, limitNum;
int convertBit[10][10] = {
    0, 4, 3, 3, 4, 3, 2, 3, 1, 2,
    4, 0, 5, 3, 2, 5, 6, 1, 5, 4,
    3, 5, 0, 2, 5, 4, 3, 4, 2, 3,
    3, 3, 2, 0, 3, 2, 3, 2, 2, 1,
    4, 2, 5, 3, 0, 3, 4, 3, 3, 2,
    3, 5, 4, 2, 3, 0, 1, 4, 2, 1,
    2, 6, 3, 3, 4, 1, 0, 5, 1, 2,
    3, 1, 4, 2, 3, 4, 5, 0, 4, 3,
    1, 5, 2, 2, 3, 2, 1, 4, 0, 1,
    2, 4, 3, 1, 2, 1, 2, 3, 1, 0,
};

int dfs(int depth, int leftBit, string madeStr){
    if(depth == display){
        int madeNum = stoi(madeStr);
        if(1 <= madeNum && madeNum <= limitNum && madeStr != startFloor) return 1;
        return 0;
    }
    int ret = 0;
    for(int i = 0; i < 10; i++){
        int diff = convertBit[i][startFloor[depth] - '0'];
        if(diff > leftBit) continue;
        ret += dfs(depth+1, leftBit - diff, madeStr + to_string(i));
    }
    return ret;
}

int main(){
    cin >> limitNum >> display >> bitNum >> startFloor;
    int diff = display - startFloor.size();
    for(int i = 0; i < display - startFloor.size(); i++){
        zeroCnt.push_back('0');
    }
    startFloor = zeroCnt + startFloor;
    cout << dfs(0, bitNum, "");
}
