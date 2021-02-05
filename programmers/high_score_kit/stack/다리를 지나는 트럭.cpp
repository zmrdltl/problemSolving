#include <vector>
#include <queue>
 
using namespace std;
 
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, currentWeight = 0;
    queue<int> count, bridge;
    while (true) {
        int size = bridge.size();
        for (int i = 0; i < size; i++){
            int length = bridge.front();
            bridge.pop();
            if (length <= 1) {
                currentWeight -= count.front();
                count.pop();
                continue;
            }
            bridge.push(length - 1);
        }
        if (truck_weights.size() > 0 && currentWeight + truck_weights.at(0) <= weight) {
            count.push(truck_weights.at(0));
            currentWeight += truck_weights.at(0);
            bridge.push(bridge_length);
            truck_weights.erase(truck_weights.begin());
        }
        answer++;
        if (truck_weights.size() == 0 && count.size() == 0)
            break;
    }
    return answer;
}