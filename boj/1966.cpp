#include <iostream>
#include <queue>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t--){
        int N, M, ans = 0;
        queue <pair<int, int>> q;
        //내림차순으로 정렬
        priority_queue <int> pq;
        cin >> N >> M;
        for (int i = 0; i < N; i++){
            int x;
            cin >> x;
            //문서번호, 중요도
            q.push({i,x});
            pq.push(x);
        }
 
        while (!q.empty()){
            //현재 배열의 인덱스와 중요도
            int currentPage = q.front().first;
            int currentImportance = q.front().second;
            q.pop();
            //현재 우선순위가 같다면.
            if (pq.top() == currentImportance){
                pq.pop();
                ans++;
                if (currentPage == M){
                    cout << ans << '\n';
                    break;
                }
            }
            else {
                q.push({ currentPage,currentImportance });
            }
        }
    }
}
