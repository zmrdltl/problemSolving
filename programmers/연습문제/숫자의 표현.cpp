#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i+1; j <= n; j++){
            sum += j;      
            if(sum == n) {answer++;break;}
            if(sum > n) break;
        }
    }
    return answer;
}