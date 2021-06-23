#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w){
    vector <int> emptySpaces;
    int size = stations.size();
    int ans = 0;

    int space = stations[0] - w - 1;
    if(space < 0) space = 0;
    emptySpaces.push_back(space);

    for(int i = 1; i < size; i++){
        space = stations[i] - stations[i-1] - 1 - w * 2;
        if(space < 0) space = 0;
        emptySpaces.push_back(space);
    }

    space = n - stations[size - 1] - w;
    if(space < 0) space = 0;
    emptySpaces.push_back(space);

    int coverLength = w * 2 + 1;
    for(auto e : emptySpaces) {
        if(e %  coverLength) ans += e/coverLength + 1;
        else ans += e/coverLength;
    }

    return ans;
}