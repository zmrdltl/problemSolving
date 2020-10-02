#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair <int, int> pairs;
int main() {
    fastio;
    int n;
    cin >> n;
    pairs minElement;
    priority_queue <pairs,vector<pairs>,greater<pairs>> pq;
    while(n--){
        int x;
        cin >> x;
        if(x!=0){
            if(!pq.empty()){
                
                if(minElemet.first == pq.top().first){
                    cout << minElement.second <<'\n';
                }
                else{
                    cout << minElement.first <<'\n';

                }
                minElement = pq.top();
                pq.pop();
            }
            else{
                cout << 0 << '\n';
            }
        }
        else{
            pq.push({abs(x),x});
        }
    }
}