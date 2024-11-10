#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    string tmp = "";
    for(int i = 0 ; i < s.size(); i++){
        tmp+=s[i];

        if(s[i]==' ' || i == s.size()-1){
            for(int j = 0; j < tmp.size(); j++){
                if(j%2==0){
                    if('a'<=tmp[j] && tmp[j] <='z'){
                        answer += tmp[j]-'a'+'A';
                    }else answer += tmp[j];
                }else{
                    if('A'<=tmp[j] && tmp[j] <='Z'){
                        answer += tmp[j]-'A'+'a';
                    }else answer += tmp[j];
                }
            }
            tmp ="";
        }
    }
    return answer;
}