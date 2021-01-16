//TODO 
#include <bits/stdc++.h>
using namespace std;
map <string,int> m;
stack <int> s;
int main(){
    string fomula;
    cin >> fomula;
    string tmp="";
    int moleculeAmount = 0;

    for(int i = 0; i < fomula.size(); i++){
        tmp+=fomula[i];
        if(fomula[i]>='2' && fomula[i]<='9'){
            tmp = tmp.substr(1,tmp.size()-3);
            int num = fomula[i] - '0';
            for(int i = 0; i < tmp.size(); i++){
                if(tmp[i]=='H') moleculeAmount+=1;
                else if(tmp[i]=='O') moleculeAmount+=16;
                else moleculeAmount+=12;
            }
            if(num){
                moleculeAmount*=num;
            }
        }else if(i == fomula.size()-1){
            tmp = tmp.substr(1,tmp.size()-2);
            int num = fomula[i] - '0';
            for(int i = 0; i < tmp.size(); i++){
                if(tmp[i]=='H') moleculeAmount+=1;
                else if(tmp[i]=='O') moleculeAmount+=16;
                else moleculeAmount+=12;
            }
            if(num>0){
                moleculeAmount*=num;
            }
        }
    }
    cout << moleculeAmount
}