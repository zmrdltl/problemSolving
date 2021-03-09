#include <iostream>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f;
using namespace std;
using vii = vector<pair<int,int>>;
using pii = pair<int,int>;

vii graph[1000001];
int d[1000001];
int number = 10;
void dijkstra(int start){
    d[start] = 0;
    priority_queue<pii,vii,greater<pii>> pq;
    pq.push({start, 0});

    while(!pq.empty()){
        int current = pq.top().first;
        int distance = pq.top().second;
        pq.pop();
        if(d[current] < distance) continue;
        for(int i = 0; i < graph[current].size(); i++){
            int next = graph[current][i].first;
            int nextDistance = distance + graph[current][i].second;
            if(nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push({next,nextDistance});
            }
        }
    }
}

int main(){
    //기본적으로 연결되지 않은 경우 비용은 무한입니다.
    for(int i = 1; i <= number; i++){
        d[i] = INF;
    }

    graph[1].push_back({2,2});
    graph[1].push_back({3,5});
    graph[1].push_back({4,1});

    graph[2].push_back({1,2});
    graph[2].push_back({3,3});
    graph[2].push_back({4,2});

    graph[3].push_back({1,5});
    graph[3].push_back({2,3});
    graph[3].push_back({4,3});
    graph[3].push_back({5,1});
    graph[3].push_back({6,5});

    graph[4].push_back({1,1});
    graph[4].push_back({2,2});
    graph[4].push_back({3,3});
    graph[4].push_back({5,1});

    graph[5].push_back({3,1});
    graph[5].push_back({4,1});
    graph[5].push_back({6,2});

    graph[6].push_back({3,5});
    graph[6].push_back({5,2});
    //1에서 i번쨰까지 가는데 드는 비용
    dijkstra(1);

    for(int i = 1; i <= number; i++)cout << d[i] << ' ';
}