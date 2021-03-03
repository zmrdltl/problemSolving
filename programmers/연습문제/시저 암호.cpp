#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0; i < s.size(); i++){
        int num;
        if('a'<=s[i] && s[i] <='z'){
            num = (s[i] -'a' + n) % 26;
            answer += num + 'a';
        }else if('A'<=s[i] && s[i] <='Z'){
            num = (s[i] -'A' + n) % 26;
            answer += num + 'A';
        }else
            answer += s[i];
    }
    return answer;
}