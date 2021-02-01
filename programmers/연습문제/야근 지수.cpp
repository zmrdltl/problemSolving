#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int,vector<int>> pq;
    for(int i = 0; i < works.size(); i++){
        pq.push(works[i]);
    }
    for(int i = 0; i < n; i++){
        if(pq.top()>0){
            long long t = pq.top() - 1;
            pq.pop();
            pq.push(t);
        }
    }
    while(!pq.empty()){
        long long t = pq.top();
        pq.pop();
        answer += pow(t,2);
    }
    return answer;
}