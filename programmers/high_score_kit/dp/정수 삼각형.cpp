#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int size = triangle.size();
    int answer = 0;
    int d[501][501];
    memset(d,0,sizeof(d));
    for(int i = 1; i <= size; i++)
        for(int j = 1; j <= triangle[i-1].size(); j++)
            d[i][j] += max(d[i-1][j-1],d[i-1][j]) + triangle[i-1][j-1];
    for(int i = 1; i <= triangle[size-1].size(); i++)
        answer = max(answer, d[triangle[size-1].size()][i]);

    return answer;
}

int main(){
    vector <vector<int>> triangle;
    triangle.push_back({7});
    triangle.push_back({3,8});
    triangle.push_back({8,1,0});
    triangle.push_back({2,7,4,4});
    triangle.push_back({4,5,2,6,5});
    cout << solution(triangle);
}
