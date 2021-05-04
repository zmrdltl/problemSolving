#include <bits/stdc++.h>
using namespace std;
int arr[101][101];

int rotate(int x1, int y1, int x2, int y2){
    vector <int> num;
    int ans = arr[x1][y1];
    int x = arr[x1][y1];
    for(int i = y1 + 1; i <= y2; i++){
        int tmp = arr[x1][i];
        ans = min(ans,tmp);
        arr[x1][i] = x;
        x = tmp;
    }
    for(int i = x1 + 1; i <= x2; i++){
        int tmp = arr[i][y2];
        ans = min(ans,tmp);
        arr[i][y2] = x;
        x = tmp;
    }
    for(int i = y2-1; i >= y1; i--){
        int tmp = arr[x2][i];
        ans = min(ans,tmp);
        arr[x2][i] = x;
        x = tmp;
    }

    for(int i = x2-1; i >= x1; i--){
        int tmp =arr[i][y1];
        ans = min(ans,tmp);
        arr[i][y1] = x;
        x = tmp;
    }
    return ans;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    memset(arr,0,sizeof(arr));
    int num = 1;
    for(int i = 1; i <= rows; i++)
        for(int j = 1; j <= columns; j++)
            arr[i][j] = num++;

    for(int i = 0; i < queries.size(); i++){
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];
        answer.push_back(rotate(x1,y1,x2,y2));
    }
    return answer;
}