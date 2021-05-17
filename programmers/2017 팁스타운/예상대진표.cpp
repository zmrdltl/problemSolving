#include <bits/stdc++.h>
using namespace std;

int dfs(int n,int a, int b, int exponents){
    if(!n) return 1;
    if(min(a,b) <= n / 2 && max(a,b) > n/2) return exponents;
    if(min(a,b) > n / 2 && max(a,b) > n / 2) return dfs(n/2, a - n/2, b - n/2, exponents - 1);    
    else return dfs(n/2, a, b, exponents - 1);    
}

//2로 나눠가면서 서로 다른 그룹이라면 return 
int solution(int n, int a, int b){
    int exponents = 0;
    while(1 << exponents != n) exponents++;
    return dfs(n, a, b, exponents);    
}