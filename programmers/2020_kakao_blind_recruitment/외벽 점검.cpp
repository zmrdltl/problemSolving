#include <bits/stdc++.h>
using namespace std;

vector <int> rotateWeak(int n, vector<int> weak){
    vector <int> tmp;
    for(int i = 1; i < weak.size(); i++) tmp.push_back(weak[i]);
    tmp.push_back(weak[0] + n);
    return tmp;
}

int solution(int n, vector<int> weak, vector<int> dist) {
 
    int answer = 0x3f3f3f3f;
 
    sort(dist.begin(), dist.end());
    do {
        for (int i = 0; i < weak.size(); i++) {
            weak = rotateWeak(n,weak);
 
            int weakIdx = 0;
            int distIdx = 0;

            for (distIdx = 0; distIdx < dist.size(); distIdx++) {
                int coverLength = weak[weakIdx] + dist[distIdx];
                while (weakIdx != weak.size() && coverLength >= weak[weakIdx]) weakIdx++;
                if(weakIdx == weak.size()) break;
            }
            if (weakIdx == weak.size()) answer = min(answer,distIdx + 1);
        }
    } while (next_permutation(dist.begin(), dist.end()));
    if(answer == 0x3f3f3f3f) return -1;
    return answer;
}
