#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int l = 0;
    int r = people.size() - 1;
    sort(people.rbegin(), people.rend());
    while(l<=r){
        if(people[l]+people[r]>limit){
            answer++;
            l++;
        }else{
            answer++;
            r--;
            l++;
        }
    }
    return answer;
}