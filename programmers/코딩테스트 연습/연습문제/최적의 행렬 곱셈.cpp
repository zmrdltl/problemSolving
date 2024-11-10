#include <bits/stdc++.h>
using namespace std;

const int sz=5e2+1;
int mn,m,mat[sz][2],memo[sz][sz];

int solve(int s,int e){
    int ret=0;
    if(s==e)return 0;
    if(memo[s][e])return memo[s][e];
    if(e==s+1){
        ret=mat[s][0]*mat[s][1]*mat[e][1];
        memo[s][e]=ret;
        return memo[s][e];
    }
    for(int i=s;i<e;++i){
        ret=solve(s,i)+solve(i+1,e)+mat[s][0]*mat[i][1]*mat[e][1];
        if(!memo[s][e]||ret<memo[s][e])memo[s][e]=ret;
    }
    return memo[s][e];
}

int solution(vector<vector<int>> matrix_sizes) {
    memset(mat,0,sizeof(mat));
    memset(memo,0,sizeof(memo));
    for(int i  =0; i < matrix_sizes.size(); i++){
        mat[i][0] = matrix_sizes[i][0];
        mat[i][1] = matrix_sizes[i][1];
    }
    return solve(0,matrix_sizes.size()-1);
}