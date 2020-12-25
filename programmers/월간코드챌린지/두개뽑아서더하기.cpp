#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
set<int> ans;
int a[101];
int visit[101];
void backtracking(vector <int> numbers, int level){
    if(level==2){
        int sum = 0;
        for(int i = 0; i < 2; i++){
            sum += a[i];
        }
        ans.insert(sum);
        return;
    }
    
    for(int i = 0; i < numbers.size(); i++){
        if(!visit[i]){
            a[level] = numbers[i];
            visit[i] = 1;
            backtracking(numbers,level+1);
            visit[i] = 0;
        }

    }
}
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    backtracking(numbers,0);
    for(auto i : ans){
        answer.push_back(i);
    }
    return answer;
}

