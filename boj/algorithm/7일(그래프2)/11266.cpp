#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> vc[10002];
int discovered[10002];
bool isCut[10002];
 
int number;
 
// here == ���� A
int dfs(int here, bool isRoot){
    discovered[here] = ++number; // DFS Ž�� ���� ����
    int ret = discovered[here];
 
    int child = 0; // �ڽ� �� count
 
    for (int i = 0; i < vc[here].size(); i++){
        int next = vc[here][i];
 
        /* 
         ���� �̹� DFS���� Ž���� �����̶�� 
         ���� ������ �湮������ Ž���� ������ �湮 ������ min���� ã�´�.
         �� ����� �̿��ؾ� 
         " A�� �������� �ڽ� ������ ���� A�� ��ġ�� �ʰ� 
         ���� A���� ���� �湮��ȣ�� ���� �������� �� �� ���ٸ� �������̴�. "
         �� ã�� �� �ִ�.
        */
        if (discovered[next]){
            ret = min(ret, discovered[next]);
            continue;
        }
 
        child++;
        int prev = dfs(next, false);
 
        /*
            ���� A�� ��Ʈ�� �ƴ϶�� ::
            A�� �������� �ڽ� ������ ���� A�� ��ġ�� �ʰ� ���� A���� ���� �湮��ȣ�� ���� �������� �� �� ���ٸ� �������̴�.
        */
        if (!isRoot && prev >= discovered[here])
            isCut[here] = true;
 
        ret = min(ret, prev);
    }
 
    /*
        ���� A�� ��Ʈ ��� ::
        �ڽ� ���� 2�� �̻��̸� �������̴�.
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
 
 
