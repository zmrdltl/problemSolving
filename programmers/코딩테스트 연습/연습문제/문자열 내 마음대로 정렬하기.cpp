#include <bits/stdc++.h>
using namespace std;

int idx;
bool cmp(string &a, string &b){
    if(a[idx]!=b[idx]) return a[idx] < b[idx];
    return a < b;
}

vector<string> solution(vector<string> strings, int n) {
    idx = n;
    sort(strings.begin(),strings.end(),cmp);
    return strings;
}