#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct build {
    int num, time;
};

build buildings[501];
int n, tmp;
int insertDegree[501];

bool operator < (const build& a, const build& b) {
    if (a.time != b.time)
        return a.time > b.time;
    return a.num > b.num;
}


 
int main() {
    cin >> n;
    vector<vector<int>> v(n + 1);
 
    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        buildings[i].time = tmp;
        while (1) {
            scanf("%d", &tmp);
            if (tmp == -1)
                break;
            v[tmp].push_back(i);
            insertDegree[i]++;
        }
    }

    priority_queue<build> q;
    //진입차수가 0인 큐를 모두 넣어준다.
    for (int i = 1; i <= n; ++i) {
        if (!insertDegree[i])
            q.push({i,buildings[i].time});
    }
 
    while (!q.empty()) {
        int cur = q.top().num;
        q.pop();
        for (auto next : v[cur]) {
            insertDegree[next]--;
            if (!insertDegree[next]) {
                buildings[next].time += buildings[cur].time;
                q.push({next, buildings[next].time});
            }    
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d\n", buildings[i].time);
 
}
