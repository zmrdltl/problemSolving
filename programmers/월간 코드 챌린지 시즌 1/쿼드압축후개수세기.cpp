#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector <int> a(2,0);
bool needDivision(vector<vector<int>> &arr, int i,int j ,int size) {
    int source = arr[i][j];
    for(int x = i; x<i+size; x++){
        for(int y = j; y < j + size; y++){
            if(source!=arr[x][y]) return 1;
        }
    }
    return 0;
}
void quadTree(vector <vector<int>> &arr,int i,int j,int size){
    if(needDivision(arr,i,j,size)){
        quadTree(arr,i + size/2, j + size/2,size/2);
        quadTree(arr,i, j + size/2,size/2);
        quadTree(arr,i + size/2, j ,size/2);
        quadTree(arr,i, j,size/2);
    } else{
        if(arr[i][j]==1) a[1]++;
        else a[0]++;
        return;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    int size = arr.size();
    quadTree(arr,0,0,size);
    return a;
}