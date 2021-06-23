#include <bits/stdc++.h>
using namespace std;
 
int solution(vector<int> sticker){
    int answer = 0;
    int size = sticker.size();
    vector <int> d(size,0);
    if (size == 1) return sticker[0];
    d[0] = sticker[0];
    d[1] = sticker[0];
    for (int i = 2; i < size - 1; i++)
        d[i] = max(d[i - 2] + sticker[i], d[i - 1]);
    answer = d[size - 2];
    d[0] = 0;
    d[1] = sticker[1];
    for (int i = 2; i < size; i++)
        d[i] = max(d[i - 2] + sticker[i], d[i - 1]);
    answer = max(answer,d[size-1]);
    return answer;
}
