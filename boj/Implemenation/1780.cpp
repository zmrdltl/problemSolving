#include <iostream>
using namespace std;

int n;
int paper[2200][2200];
int zeroPaper;
int minusPaper;
int onePaper;

bool isPaper(int i,int j,int width){
    int pivot = paper[i][j];
    for(int x = i; x < i + width; x++){
        for(int y = j; y < j + width; y++){
            if(pivot!=paper[x][y]){
                return 0;
            }
        }
    }
    return 1;
}

void cutPaper(int i,int j,int n){
    if(!isPaper(i,j,n)){
        //1~3행
        cutPaper(i,j,n/3);
        cutPaper(i,j+n/3,n/3);
        cutPaper(i,j+n/3*2,n/3);
        //4~6행
        cutPaper(i+n/3,j,n/3);
        cutPaper(i+n/3,j+n/3,n/3);
        cutPaper(i+n/3,j+n/3*2,n/3);
        //7~9행
        cutPaper(i+n/3*2,j,n/3);
        cutPaper(i+n/3*2,j+n/3,n/3);
        cutPaper(i+n/3*2,j+n/3*2,n/3);
    }else{
        if(paper[i][j]==0) zeroPaper++;
        else if(paper[i][j]==1) onePaper++;
        else minusPaper++;
    }
    
    return;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> paper[i][j];
    cutPaper(0,0,n);
    cout << minusPaper << '\n';
    cout << zeroPaper << '\n';
    cout << onePaper << '\n';
}