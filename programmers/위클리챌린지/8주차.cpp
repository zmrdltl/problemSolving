#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0x3f3f3f3f;
    int width = 0, height = 0;
    for(auto &s : sizes) {
        sort(s.begin(), s.end());
        width = max(width, s[0]);
        height = max(height, s[1]);
    }
    return width * height;
}