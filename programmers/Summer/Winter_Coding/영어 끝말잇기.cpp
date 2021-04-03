#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map <string,int> m;
    
    int turn = 0, people = 0;
    for(int i = 0; i < words.size(); i++){
        turn = i/n + 1;
        
        if(i){
            if(words[i-1][words[i-1].size()-1] != words[i][0] || m[words[i]] == 1){
                people = i % n + 1;
                break;
            }
        }
        m[words[i]] = 1;
    }
    if(!people) turn = 0;
    answer.push_back(people);
    answer.push_back(turn);
    return answer;
}