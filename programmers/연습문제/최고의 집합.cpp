#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, int s) {
    int start = s/n;
    int margin = s % n;
    if(start == 0) return {-1};
    vector<int> answer(n,start);
    for(int i = n - 1; i > n - 1 - margin; i--){
        answer[i]++;
    }        
    return answer;
}