#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
int map[51][51];
struct info{
    int x,y
};
vector <pair<info,bool ck>> chicken;
vector <info> home;
int n,m;

int cal(int x1,int x2,int y1,int y2){
    return abs(x1-x2) + abs(y1-y2);
}

int backtracking(){

}


int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> map[i][j];
    }

}