#include <iostream>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f;
using namespace std;
using vii = vector<pair<int,int>>;
using pii = pair<int,int>;

vii graph[1000001];
int dis[1000001];
int number = 10;

void dijkstra(int start){
    dis[start] = 0;
    
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0, start});
    while (!pq.empty()){
        int currentDistance = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (currentDistance > dis[current]) continue;

        for (int i = 0; i < graph[current].size(); i++){
            int nextDistance = graph[current][i].first;
            int next = graph[current][i].second;
            if (nextDistance + currentDistance < dis[next]){
                dis[next] = nextDistance + currentDistance;
                pq.push({dis[next], next});
            }
        }
    }
}

int main(){
    //기본적으로 연결되지 않은 경우 비용은 무한입니다.
    for(int i = 1; i <= number; i++){
        dis[i] = INF;
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

    for(int i = 1; i <= number; i++)cout << dis[i] << ' ';
}