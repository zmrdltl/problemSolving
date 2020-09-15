#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n, m,ans;
int paper[501][501];

int getFirstShape(int i,int j){
    int tmp = 0;
    if(0 <= i && i < n && 0 <= j && j + 3 <m){
        tmp = max(tmp,paper[i][j]+paper[i][j+1]+paper[i][j+2] + paper[i][j+3]);
    }
    if(0 <= i && i + 3 < n && 0 <= j && j < m){
        tmp = max(tmp,paper[i][j]+paper[i+1][j]+paper[i+2][j] + paper[i+3][j]);
    }
    return tmp;
}

int getSecondShape(int i,int j){
    if(0 <= i && i + 1 < n && 0 <= j && j + 1 <m)
        return paper[i][j]+paper[i][j+1]+paper[i+1][j]+paper[i+1][j+1];
    return 0;
}

int getThirdShape(int i,int j) {
    int tmp = 0;
    if(0 <= i && i + 2 < n && 0 <= j && j + 1 < m)
        tmp = max(tmp,paper[i][j] + paper[i+1][j]+paper[i+2][j]+paper[i+2][j+1]);
    if(0 <= i && i + 2 < n && 0 <= j - 1 && j - 1 < m)
        tmp = max(tmp,paper[i][j] + paper[i+1][j]+paper[i+2][j]+paper[i+2][j-1]);
    if(0 <= i && i + 1 < n && 0 <= j && j + 2 < m)
        tmp = max(tmp,paper[i][j] + paper[i+1][j]+paper[i][j+1]+paper[i][j+2]);
    if(0 <= i && i + 1 < n && 0 <= j && j + 2 < m)
        tmp = max(tmp,paper[i][j] + paper[i+1][j]+paper[i+1][j+1]+paper[i+1][j+2]);
    if(0 <= i && i + 2 < n && 0 <= j && j + 1 < m)
        tmp = max(tmp,paper[i][j] + paper[i][j+1]+paper[i+1][j+1]+paper[i+2][j+1]);
    if(0 <= i && i + 2 < n && 0 <= j && j + 1 < m)
        tmp = max(tmp,paper[i][j] + paper[i+1][j]+paper[i+2][j]+paper[i][j+1]);
    if(0 <= i && i + 1 < n && 0 <= j - 2 && j < m)
        tmp = max(tmp,paper[i][j] + paper[i+1][j]+paper[i+1][j-1]+paper[i+1][j-2]);
    if(0 <= i && i + 1 < n && 0 <= j - 2 && j < m)
        tmp = max(tmp,paper[i][j] + paper[i][j-1]+paper[i][j-2]+paper[i+1][j]);
    return tmp;
}

int getForthShape(int i,int j){
    int tmp = 0;
    if(0 <= i && i + 2 < n && 0 <= j && j + 1 <m)    
        tmp = max(tmp,paper[i][j]+paper[i+1][j]+paper[i+1][j+1]+paper[i+2][j+1]);
    if(0 <= i - 1 && i < n && 0 <= j && j + 2 < m)
        tmp = max(tmp,paper[i][j]+paper[i][j+1]+paper[i-1][j+1]+paper[i-1][j+2]);
    if(0 <= i && i + 2 < n && 0 <= j - 1 && j < m)
        tmp = max(tmp,paper[i][j]+paper[i+1][j]+paper[i+1][j-1]+paper[i+2][j-1]);
    if(0 <= i && i + 1 < n && 0 <= j && j + 2 < m)
        tmp = max(tmp,paper[i][j]+paper[i][j+1]+paper[i+1][j+1]+paper[i+1][j+2]);
    return tmp;
}

int getFifthShape(int i, int j){
    int tmp = 0;

    if(0 <= i && i + 1 < n && 0 <= j && j + 2 < m)
        tmp = max(tmp,paper[i][j]+paper[i][j+1]+paper[i][j+2]+paper[i+1][j+1]);
    if(0 <= i && i + 2 < n && 0 <= j && j + 1 < m)  
        tmp = max(tmp,paper[i][j]+paper[i+1][j]+paper[i+1][j+1]+paper[i+2][j]);
    if(0 <= i - 1 && i < n && 0 <= j && j + 2 < m)
        tmp = max(tmp,paper[i][j]+paper[i][j+1]+paper[i-1][j+1]+paper[i][j+2]);
    if(0 <= i && i + 2 < n && 0 <= j - 1 && j < m)
        tmp = max(tmp,paper[i][j]+paper[i+1][j]+paper[i+1][j-1]+paper[i+2][j]);
    return tmp;
}

int tetromino(int i,int j) {
    int answer = 0;
    answer = max(answer,getFirstShape(i,j));
    answer = max(answer,getSecondShape(i,j));
    answer = max(answer,getThirdShape(i,j));
    answer = max(answer,getForthShape(i,j));
    answer = max(answer,getFifthShape(i,j));
    return answer;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> paper[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ans = max(ans,tetromino(i,j));
    cout << ans <<'\n';
}