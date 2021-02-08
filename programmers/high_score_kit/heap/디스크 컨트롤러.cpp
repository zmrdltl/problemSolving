#include <bits/stdc++.h>
using namespace std;
 
struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
    }
};
 
int solution(vector<vector<int>> jobs) {
    int totalTime = 0, j = 0, currentTime = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    while (j < jobs.size() || !pq.empty()) {
        if (jobs.size() > j && currentTime >= jobs[j][0]) {
            pq.push(jobs[j++]);
            continue;
        }
        if (!pq.empty()) {
            currentTime += pq.top()[1];
            totalTime += currentTime - pq.top()[0];
            pq.pop();
        }
        else
            currentTime = jobs[j][0];
    }
    return totalTime / jobs.size();
}