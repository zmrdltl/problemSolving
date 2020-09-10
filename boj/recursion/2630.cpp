#include <iostream>
using namespace std;
int paper[130][130];
int n;
int whiteNum;
int blueNum;
bool isSameColor(int i, int j, int width){
    int color = paper[i][j];
    for(int x = i; x < i + width; x++)
        for(int y = j; y < j + width; y++)
            if(paper[x][y]!=color)
                return 0;
    return 1;
}

void cutPaper(int i,int j,int n){
    if(!isSameColor(i,j,n)){
        cutPaper(i+n/2,j+n/2,n/2);
        cutPaper(i,j+n/2,n/2);
        cutPaper(i+n/2,j,n/2);
        cutPaper(i,j,n/2);
    }else{
        if(paper[i][j]==0)
            whiteNum+=1;
        else
            blueNum+=1;
    }
    return;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> paper[i][j];
    cutPaper(0,0,n);
    cout << whiteNum << '\n' << blueNum << '\n';
}