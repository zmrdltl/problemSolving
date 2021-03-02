#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> numbers) {
    set <int> s;
    for(int i = 0; i < numbers.size(); i++){
        for(int j = i+1; j < numbers.size(); j++){
            s.insert(numbers[i] + numbers[j]);
        }
    }
    vector <int> ans;
    for(auto p:s) ans.push_back(p);
    return ans;
}
