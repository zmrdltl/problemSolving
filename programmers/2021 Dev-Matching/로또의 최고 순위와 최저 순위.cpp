#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int match=0,notMatch=0,big=0,small=0;
    for(int i = 0; i < lottos.size(); i++){
        if(!lottos[i]) notMatch++;
        for(int j = 0; j < win_nums.size(); j++){
            if(lottos[i] == win_nums[j]) match++;
        }
    }
    big = 7 - (match + notMatch);
    if(big == 7) big = 6;
    small = 7 - match;
    if(small == 7) small = 6;
    return {big,small};
}