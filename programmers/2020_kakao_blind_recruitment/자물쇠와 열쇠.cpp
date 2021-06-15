#include <bits/stdc++.h>
using namespace std;

//시계방향 90도 회전
void rotateKey(vector<vector<int>> &key){
    vector <vector<int>> v = key;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v.size(); j++){
            v[i][j] = key[v.size() - 1 - j][i];
        }
    }
    key = v;
}

void copyLock(int lock[50][50], int expandedLock[50][50]){
    for(int i = 0; i < 50; i++)
        for(int j = 0; j < 50; j++)
            lock[i][j] = expandedLock[i][j];
}

bool canOpen(int lock[50][50], int n){
    for(int i = 20; i < 20 + n; i++)
        for(int j = 20; j < 20 + n; j++)
            if(!lock[i][j]) return false;
    return true;
}

bool isSafeRange(int i, int j, int r, int c, int n){
    if(20 <= i + r && i + r < 20 + n && 20 <= j + c && j + c < 20 + n) return true;
    return false;
}


bool validCheck(vector<vector<int>>key, int expandedLock[50][50], int n){
    int lock[50][50];

    for(int r = 0; r < 50; r++){
        for(int c = 0; c < 50; c++){
            copyLock(lock, expandedLock);
            for(int i = 0; i < key.size(); i++){
                for(int j = 0; j < key.size(); j++){
                    if(!isSafeRange(i,j,r,c,n)) continue;
                    if(!key[i][j] && !lock[i+r][j+c] || key[i][j] && lock[i+r][j+c]) break;
                    if(key[i][j] == 1 && !lock[i+r][j+c]) lock[i+r][j+c] = 1;
                }
            }   
            if(canOpen(lock, n)) return true;
        }
    }

    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int expandedLock[50][50] = {0};

    for(int i = 0; i < lock.size(); i++)
        for(int j = 0; j < lock.size(); j++)
            expandedLock[i + 20][j + 20] = lock[i][j];

    
    for(int i = 0; i < 4; i++){
        if(validCheck(key, expandedLock, lock.size())) {answer = true; break;}
        rotateKey(key);
    }

    return answer;
}