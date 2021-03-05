#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) {
    auto it = arr.begin();
    int mini = 0x3f3f3f3f;
    for(auto a = arr.begin(); a!=arr.end(); a++){
        if(mini > *a) {
            mini = *a;
            it = a;
        }
    }
    arr.erase(it);
    if(!arr.size()) arr.push_back(-1);
    return arr;
}