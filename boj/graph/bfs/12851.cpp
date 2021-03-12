#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
using pii = pair<int,int>;
 
int cnt;
int minSec;
int visited[MAX];
int n,k;
int bfs(){
    queue<pii> q;
    q.push({n, 0});
    visited[n] = 1;
    while (!q.empty()){
        int pos = q.front().first;
        int sec = q.front().second;
        q.pop();
        visited[pos] = 1; 
        if(pos == k){
            //최소시간이 겹치면 
            if (minSec && minSec == sec) cnt++;
            
            //첫 빠따 제일 최소시간
            if (!minSec){
                minSec = sec;
                cnt++;
            }
        }

        if (pos + 1 < MAX && !visited[pos + 1])
            q.push({pos + 1, sec + 1});
        if (pos - 1 >= 0 && !visited[pos - 1])
            q.push({pos - 1, sec + 1});
        if (pos * 2 < MAX && !visited[pos * 2])
            q.push({pos * 2, sec + 1});
    }
    return minSec;
}

 
int main(void){
    cin >> n >> k;
    cout << bfs() << '\n';
    cout << cnt << '\n';;
}


