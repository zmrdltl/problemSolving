// BOJ 6603 로또
#include <iostream>
#include <vector>
 
using namespace std;
int n;
vector<int> num;
vector<int> result;
 
void dfs(int idx) {
    // 6개를 채우면 출력하고 dfs 탐색 중단
    if (result.size() == 6) {
        for (int r : result)
            cout << r << ' ';
        cout << '\n';
        return;
    }
    for (int i = idx; i < n; i++) {
        // 남은 노드 수가 6 이하면 탐색할 필요 없음
        if(n - i + result.size() < 6) return;
        result.push_back(num[i]);
        dfs(i + 1);
        result.pop_back();
    }
}
 
int main() {
    while (1) {
        cin >> n;
        if(!n) break;
        num = vector<int>(n);
        for (int i = 0; i < n; i++)
            cin >> num[i];
        dfs(0);
        cout << '\n';
    }
    return 0;
}