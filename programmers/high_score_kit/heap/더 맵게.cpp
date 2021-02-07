#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue <int, vector<int>, greater<int>> pq;
    for(int i = 0; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    while(!pq.empty() && pq.top() < K ){
        int scov1 = pq.top();
        pq.pop();
        int scov2 =  pq.top();
        pq.pop();
        pq.push(scov1 + scov2 * 2);
        answer++;
    }
    if(pq.top() < K) return -1;
    return answer;
}