#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int flag = 1;
    for(int i = 0; i < s.size(); i++){
        if('A' <= s[i] && s[i] <= 'Z'){
            s[i] = 'a' + s[i] -'A';
        }
    }
    for(int i = 0; i < s.size(); i++){
        if('a' <= s[i] && s[i] <= 'z' && flag){
            flag = 0;
            s[i] = 'A' + s[i] -'a';
        }
        if(s[i] == ' ') flag = 1;
        if(!i) flag = 0;
        
        answer += s[i];
    }
    return answer;
}