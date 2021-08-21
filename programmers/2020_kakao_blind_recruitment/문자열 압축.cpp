#include <bits/stdc++.h>
using namespace std;
string ans;
int solution(string s) {
    for(int i = 0; i < 1001; i++) ans.push_back('a');
    int answer = 0;
    for(int i = 1; i <= s.size(); i++){ //자르는 단위
        string compressed;
        int cnt = 1;
        
        for(int j = 0; j < s.size(); j += i*cnt){
            string block;
            string tmp = s.substr(j,i); //연속되는 단위비교를 위한 기본 문자
            cnt = 1;

            for(int k = j + i; k < s.size(); k += i){
                string cmp = s.substr(k,i); //이후 연속된 단위 문자열 개수 세주기
                if(tmp == cmp) {
                    block = tmp;
                    cnt++;
                }
                else break;
            }

            if(!block.size()) compressed += tmp; //한번도 같은적이 없었다면 바로 추가

            else{
                compressed += block;
                if(cnt >= 2) compressed += to_string(cnt); //2번 이상 연속으로 나왔다면 숫자도 추가.
            }
        }

        if(ans.size() > compressed.size()){
            ans = compressed;
            answer = compressed.size();
        }
    }
    
    return answer;
}