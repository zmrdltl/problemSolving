#include <bits/stdc++.h>
using namespace std;

void input(queue <int> &q, int num){
    int x = q.front();
    q.pop();
    for(int i  =0; i < 2; i++)
        !(i % 2) ? q.push(x + num) : q.push(x - num);
}

int bfs(vector <int> &numbers,int target){
    queue <int> q;
    q.push(numbers[0]);
    q.push(-numbers[0]);
    int cnt = 0;
    for(int i = 1; i < numbers.size(); i++){
        int sz = q.size();
        while(sz--) input(q,numbers[i]);
    }

    while(!q.empty()){
        int x = q.front();
        if (x == target) cnt++;
        q.pop();
    }

    return cnt;
}

int solution(vector<int> numbers, int target) {
    return bfs(numbers,target);
}