#include <bits/stdc++.h>
using namespace std;

//시계방향 90도 회전
void rotateKey(vector<vector<int>> &key){
    vector <vector<int>> v = key;
    for(int i = 0; i < v.size(); i++)
        for(int j = 0; j < v.size(); j++)
            v[i][j] = key[v.size() - 1 - j][i];
    key = v;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int m = key.size();
    int n = lock.size();
    for(int time = 0; time < 4; time++){
        vector<vector<int>> newkey(m,vector<int>(m,0));
        rotateKey(key);

        for(int i = 0; i < m; i++)
            for(int j = 0; j < m; j++)
                newkey[i][j] = key[i][j];

        for(int i = 0; i < n + m - 1; i++){
            for(int j = 0; j < n + m - 1; j++) {

                vector<vector<int>> newlock(2 * m - 2 + n, vector<int>(2 * m - 2 + n, 0));

                for (int r = 0; r < n; r++)
                    for (int c = 0; c < n; c++)
                        newlock[r + m - 1][c + m - 1] = lock[r][c];

                for(int r=0; r<m; r++) {
                    for (int c = 0; c < m; c++) {
                        newlock[r + i][c + j] += newkey[r][c];
                    }
                }

                int count = 0;
                for(int r = m - 1; r < m + n-  1; r++)
                    for(int c = m - 1; c < m + n - 1; c++)
                        if(newlock[r][c] == 1) count++;

                if(count == n * n) return true;
            }
        }
    }
    return false;
}
