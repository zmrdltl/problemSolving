//TODO

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    priority_queue<char,vector<char>> pq;
    pq.push("abcd");
    pq.push("bcda");
    while(!pq.empty()){
        cout << pq.top() << '\n';
        pq.pop();
    }
    return answer;
}