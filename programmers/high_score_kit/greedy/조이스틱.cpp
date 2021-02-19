#include <bits/stdc++.h> 
using namespace std;
 
int solution(string name) {
    int answer = 0, i = 0;
    string tmp(name.size(), 'A');
    while (1) {
        tmp[i] = name[i];
        name[i] - 'A' > 'Z' + 1 - name[i] ? answer += 'Z' + 1 - name[i] : answer += name[i] - 'A';
        if (tmp == name)    break;
        for (int move = 1; move < name.size(); move++) {
            if (name[(i + move) % name.size()] != tmp[(i + move) % name.size()]) {
                i = (i + move) % name.size();
                answer += move;
                break;
            }
            else if (name[(i + name.size() - move) % name.size()] 
                != tmp[(i + name.size() - move) % name.size()]) {
                i = (i + name.size() - move) % name.size();
                answer += move;
                break;
            }
        }
    }
    return answer;
}

int main(){
    cout << solution("CCCAAAAAAAAAAZZ");
}