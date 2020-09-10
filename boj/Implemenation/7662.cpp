#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int k;
bool visited[1000001];
int main(void){
    fastio;
    int testCase;
    cin >> testCase;
    while(testCase--){
        cin >> k;
        priority_queue<pair<int, int>> maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (int i = 0; i < k; i++){
            char oper;
            int atom;
            cin >> oper >> atom;
            if (oper == 'I'){
                maxHeap.push({ atom, i });
                minHeap.push({ atom, i });
                visited[i] = true;
            }
            else{
                if (atom == 1){
                    while (!maxHeap.empty() && !visited[maxHeap.top().second])
                        maxHeap.pop();
                    if (!maxHeap.empty()){
                        //pop하므로 유효하지 않다고 표시
                        visited[maxHeap.top().second] = false;
                        maxHeap.pop();
                    }
                }
                else{
                    while (!minHeap.empty() && !visited[minHeap.top().second])
                        minHeap.pop();
                    if (!minHeap.empty()){
                        visited[minHeap.top().second] = false;
                        minHeap.pop();
                    }
                }
            }

        }
        while (!maxHeap.empty() && !visited[maxHeap.top().second])
            maxHeap.pop();
        while (!minHeap.empty() && !visited[minHeap.top().second])
            minHeap.pop();
        if (minHeap.empty() && maxHeap.empty())
            cout << "EMPTY\n";
        else
            cout << maxHeap.top().first << " " << minHeap.top().first << "\n";
    }
}

 

