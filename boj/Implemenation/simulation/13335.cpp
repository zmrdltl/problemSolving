#include <iostream>
#include <queue>
using namespace std;
int n, length, weight, curWeight;
int truck[1001];
queue <int> bridge;

int time;
int main(){
    cin >> n >> length >> weight;
    for(int i = 0; i < n; i++) cin >> truck[i];
    for(int i = 0; i < n; i++){
        while(1){
            if(bridge.size()==length){
                curWeight -= bridge.front();
                bridge.pop();
            }
            if(curWeight + truck[i] <= weight) break;
            bridge.push(0);
            time++;
        }
        bridge.push(truck[i]);
        curWeight += truck[i];
        time++;
    }
    cout << time + length <<'\n';
}