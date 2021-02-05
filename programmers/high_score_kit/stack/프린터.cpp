#include <bits/stdc++.h>
using namespace std;
 
int solution(vector<int> priorities, int location) {
    int answer = 0, cnt = 0;
    queue<pair<int, int>> q;
    priority_queue <int> pq;
 
    for (int i = 0; i < priorities.size(); i++) {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    while (!q.empty()) {
        int index = q.front().first;
        int value = q.front().second;
        q.pop();
        if (pq.top() == value) {
            pq.pop();
            cnt++;
            if (index == location) {
                answer = cnt;
                break;
            }
            continue;
        }
        q.push({index, value});
    }
    return answer;
}