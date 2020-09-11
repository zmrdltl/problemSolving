#include <iostream>
#include <queue>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n;
priority_queue <int,vector<int>> pqMaxHeap; //pq는 default가 less, maxHeap

int main(){
    fastio;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(x>0){
            pqMaxHeap.push(x);
        }else{
            if(pqMaxHeap.empty()){
                cout << 0 <<'\n';
            }else{
                cout << pqMaxHeap.top() <<'\n';
                pqMaxHeap.pop();
            }

        }
    }
}