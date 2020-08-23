#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int d[50][50];
vector <vector <int>> v(1001);
int n = 6;
int k = 4;
int floyd(){
    for(auto & p : v){
        d[p[0]-1][p[1]-1] = d[p[1]-1][p[0]-1] = p[2];
    }
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0 ; j<n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
int main(){
    v.push_back({1, 2, 1});
    v.push_back({2, 3, 3});
    v.push_back({5, 2, 2});
    v.push_back({1,4 ,2});
    v.push_back({5,3,1});
    v.push_back({5,4,2});
    cout << floyd();
}