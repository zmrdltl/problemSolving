#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll getNum(string diffBitString){
    ll sum = 0;
    ll cnt = 1;
    for(int i = diffBitString.size() - 1; i >= 0; i--){
        sum += cnt * (diffBitString[i] - '0');
        cnt *= 2;
    }
    return sum;
}



// 001011101011010101011
vector<ll> solution(vector<ll> numbers) {
    vector<ll> answer;
    for(auto number:numbers){
        string s="";
        for(int i=0;i<64;i++){
            if(number&(1L<<i)){
                s+='1';
            }else{
                s+='0';
            }
        }
        reverse(s.begin(),s.end());
        int idx=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                idx=i;
                break;
            }
        }
        // 111010101010
        int flag=0;
        for(int i=(int)s.size()-1;i>idx;i--){
            if(s[i]=='0'){
                flag=1;
                string k=s;
                k[i]='1';
                if(i!=(int)s.size()-1){
                    k[i+1]='0';
                }
                answer.push_back(getNum(k));
                break;
            }
        }
        if(flag==0){
            s[idx]='0';
            s[idx-1]='1';
            answer.push_back(getNum(s));
        }
    }
    return answer;
}