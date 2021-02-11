#include <bits/stdc++.h>

using namespace std;
int dfs(int depth, int num, vector <int> &numbers, int target){
    if(depth == numbers.size()){
        return num == target;
    }
    int cnt = 0;
    cnt += dfs(depth+1, num + numbers[depth], numbers, target);
    cnt += dfs(depth+1, num - numbers[depth], numbers, target);
    return cnt;
}

int solution(vector<int> numbers, int target) {
    return dfs(0,0, numbers, target);
}