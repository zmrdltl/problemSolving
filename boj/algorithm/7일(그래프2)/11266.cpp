#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> vc[10002];
int discovered[10002];
bool isCut[10002];
 
int number;
 
// here == 정점 A
int dfs(int here, bool isRoot){
    discovered[here] = ++number; // DFS 탐색 순서 지정
    int ret = discovered[here];
 
    int child = 0; // 자식 수 count
 
    for (int i = 0; i < vc[here].size(); i++){
        int next = vc[here][i];
 
        /* 
         만약 이미 DFS에서 탐색된 정점이라면 
         현재 정점의 방문순서와 탐색된 정점의 방문 순서중 min값을 찾는다.
         이 방법을 이용해야 
         " A번 정점에서 자식 노드들이 정점 A를 거치지 않고 
         정점 A보다 빠른 방문번호를 가진 정점으로 갈 수 없다면 단절점이다. "
         를 찾을 수 있다.
        */
        if (discovered[next]){
            ret = min(ret, discovered[next]);
            continue;
        }
 
        child++;
        int prev = dfs(next, false);
 
        /*
            정점 A가 루트가 아니라면 ::
            A번 정점에서 자식 노드들이 정점 A를 거치지 않고 정점 A보다 빠른 방문번호를 가진 정점으로 갈 수 없다면 단절점이다.
        */
        if (!isRoot && prev >= discovered[here])
            isCut[here] = true;
 
        ret = min(ret, prev);
    }
 
    /*
        정점 A가 루트 라면 ::
        자식 수가 2개 이상이면 단절점이다.
    */
    if (isRoot)
        isCut[here] = (child >= 2);
 
    return ret;
}
int main(){
    int V, E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++){
        int from, to;
        scanf("%d %d", &from, &to);
 
        vc[from].push_back(to);
        vc[to].push_back(from);
    }
 
    for (int i = 1; i <= V; i++)
        if (!discovered[i])
            dfs(i, true);
 
    int cnt = 0;
    for (int i = 1; i <= V; i++)
        if (isCut[i])
            cnt++;
 
    printf("%d\n", cnt);
    for (int i = 1; i <= V; i++)
        if (isCut[i])
            printf("%d ", i);
}
 
 
