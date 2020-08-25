#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map <string,int> m;
    for (int i = 0; i < participant.size(); i++) m[participant[i]]++;
	for (int i = 0; i < completion.size(); i++) m[completion[i]]--;
	for (int i = 0; i < participant.size(); i++) if (m[participant[i]]>0) return participant[i];
}

int main(){
    vector<string>participant({"marina", "josipa", "nikola", "vinko", "filipa"});
    vector<string>completion({"josipa", "filipa", "marina", "nikola"});
    cout << solution(participant,completion);
}