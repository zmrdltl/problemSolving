#include <bits/stdc++.h>
using namespace std;
void extract(string &oneWord, string &oneOneZero ){
    oneOneZero = "";
    deque <char> dq;
    int cnt = 0;
    //110
    //11110000
    for(int i = 0; i < oneWord.size(); i++){
        int flag = 0;
        while(oneWord[i] == '0' && cnt >= 2 && dq.size() >= 2){
            oneOneZero += "110";
            dq.pop_back();
            dq.pop_back();
            cnt -= 2;
            flag = 1;
        }
        if(flag) continue;
        if(cnt < 2) {
            if(oneWord[i] == '1') cnt++;
            dq.push_back(oneWord[i]);
        }

        
        cout << "DQ : \n";
        for(auto d : dq) cout << d << ' ';
        cout << '\n';
        if(oneWord[i] == '0') cnt = 0;
    }

    oneWord = "";
    while(!dq.empty()){
        oneWord += dq.front();
        dq.pop_front();
    }

    cout << "ÀÏÀÏ¿µ : " <<  oneOneZero << '\n';

}

void insert(string &oneWord, string &oneOneZero ){
    if(oneWord.size() < 3){
        oneWord = oneOneZero + oneWord;
        return;
    }
    int idx = oneWord.find("111");
    string tmp;
    for(int i = 0; i < idx; i++){
        tmp += oneWord[i];
    }
    tmp += oneOneZero;
    for(int i = idx+1; i < oneWord.size(); i++) tmp += oneWord[i];
    oneWord = tmp;
}

vector<string> solution(vector<string> s) {
    string oneOneZero = "";
    for(int i = 0; i < s.size(); i++){
        extract(s[i],oneOneZero);
        cout << "Ex : " << s[i] << '\n';
        insert(s[i],oneOneZero);
        cout << "insert : " << s[i] << '\n';
    }
    //sort(s.begin(), s.end());
    return s;
}