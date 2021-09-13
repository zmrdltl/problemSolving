#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int d[1001][3];
int answer,maxVal;
int n,a,b;
int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        d[a][0] = b;
    }
    for(int i = 0; i <= 1000; i++){
        maxVal = max(d[i][0], maxVal);
        d[i][1] = maxVal;
    }
    maxVal = 0;
    for(int i = 1000; i >= 0; i--){
        maxVal = max(d[i][0], maxVal);
        d[i][2] = maxVal;
    }
    for(int i = 0; i <= 1000; i++) answer += min(d[i][1], d[i][2]);
    cout << answer;
}