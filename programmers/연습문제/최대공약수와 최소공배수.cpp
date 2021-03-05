#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    int g = gcd(n,m);
    answer.push_back(g);
    answer.push_back(n/g*m/g*g);
    return answer;
}