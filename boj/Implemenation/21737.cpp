#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, cFlag, output, idx;
string s;
vector <ll> nums;
vector <char> op;

void parsing(){
    string tmp;
    for(ll i = 0; i < s.size(); i++){
        if(s[i] == 'S' || s[i] == 'M' || s[i] == 'U' || s[i] == 'P' || s[i] == 'C' || i == s.size() - 1){
            if(s[i] == 'C') cFlag = 1;
            op.push_back(s[i]);
            if(tmp.size()) nums.push_back(stoi(tmp));
            tmp = "";
            continue;
        }
        tmp += s[i];
    }
}

void operating(){
    output = nums[0];
    for(auto o : op){
        if(o == 'S') output -= nums[++idx];
        else if(o == 'M') output *= nums[++idx];
        else if(o == 'U'){
            if(output < 0) output = -(-output / nums[++idx]);
            else output = output / nums[++idx];
        }
        else if(o == 'P') output += nums[++idx];
        else cout << output << ' ';
    }
}

int main(){
    cin >> n >> s;
    
    parsing();

    if(!cFlag){ cout << "NO OUTPUT"; return 0; }

    operating();
}