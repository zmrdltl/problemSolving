#include <bits/stdc++.h>
using namespace std;
string toLowerCase(string new_id){
    string tmp = "";
    for(int i = 0; i < new_id.size(); i++){ 
        if('A'<=new_id[i] && new_id[i] <= 'Z'){
            tmp += new_id[i] -'A' +'a';
        }else tmp+= new_id[i];
    }
    return tmp;
}

string secondPhase(string new_id){
    string tmp = "";
    for(int i = 0; i < new_id.size(); i++){
        if(isalpha(new_id[i]) || '0' <= new_id[i] && new_id[i] <='9' ||
            new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            tmp+=new_id[i];
    }
    return tmp;
}

string thirdPhase(string new_id){
    string tmp = "";
    for(int i = 0; i < new_id.size(); i++){
        tmp += new_id[i];
        if(new_id[i]=='.'){
            int j = i;
            while(new_id[j++]=='.');
            i = j - 2;
        }
    }
    return tmp;
}

string fourthPhase(string new_id){
    string tmp = "";
    for(int i = 0; i < new_id.size(); i++){
        if(i == 0  && new_id[i] == '.' || i == new_id.size()-1 && new_id[i] == '.') continue;
        tmp += new_id[i];
    }
    return tmp;
}

string fifthPhase(string new_id){
    if(!new_id.size()) return "a";
    else return new_id;
}

string sixthPhase(string new_id){
    string tmp = "";
    if(new_id.size() > 15){
        tmp = new_id.substr(0,15);
    }
    else tmp = new_id;
    if(tmp[tmp.size()-1] == '.') 
        return tmp.substr(0,tmp.size()-1);
    return tmp;
}

string seventhPhase(string new_id){
    string tmp = new_id;
    int size = tmp.size();
    if(tmp.size() <= 2){
        while(size < 3){
            tmp+=new_id[new_id.size()-1];
            size = tmp.size();
        }
    }
    return tmp;
}

string solution(string new_id) {
    string answer = "";
    new_id = toLowerCase(new_id);
    new_id = secondPhase(new_id);
    new_id = thirdPhase(new_id);
    new_id = fourthPhase(new_id);
    new_id = fifthPhase(new_id);
    new_id = sixthPhase(new_id);
    new_id = seventhPhase(new_id);    
    return new_id;
}

int main(){
    //cout << solution("") <<'\n';
    cout << solution("z-+.^.") <<'\n';
}
