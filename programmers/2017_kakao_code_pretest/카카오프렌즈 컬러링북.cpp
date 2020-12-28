#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int visit[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int bfs(int i, int j, int m,int n, vector<vector<int>> picture){
    queue <pair<int,int>> q;
    q.push({i,j});
    int area = 1;
    int areaNum = picture[i][j];
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(picture[nx][ny] == areaNum && !visit[nx][ny]){
                q.push({nx,ny});
                visit[nx][ny] = 1;
                area++;
            }
        }
    }
    return area;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    memset(visit,0,sizeof(visit));
    vector<int> answer(2);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visit[i][j] && picture[i][j]){
                visit[i][j] = 1;
                number_of_area++;
                int area = bfs(i,j,m,n,picture);
                max_size_of_one_area = max(area,max_size_of_one_area);
            }
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}   