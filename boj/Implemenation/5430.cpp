#include <iostream>
#include <string>
#include <deque>
using namespace std;
int testCase;
deque <int> dq;
int main(){
    
    cin >> testCase;

    while(testCase--){
        int flag = 0;
        int rCount = 0;
        int arrayLength;
        string arrayString;
        string operation;
        cin >> operation >> arrayLength >> arrayString;
        for(int i = 1; i < arrayString.size(); i++){
            string num = "";
            while(arrayString[i]!=',' && arrayString[i]!=']') num += arrayString[i++];
            if(num!="") dq.push_back(stoi(num));
        }
        for(int i = 0; i < operation.size(); i++){
            if(operation[i] == 'R') rCount++;
            else {
                if(dq.size()==0) {
                    flag = 1;
                    cout << "error";
                    break;
                }
                if(rCount % 2 == 0) dq.pop_front();
                else dq.pop_back();
            }
        }

        int cnt = 0;
        int size = dq.size();
        
        while(dq.size()){
            if(cnt==0) cout << "[";

            if(rCount % 2 == 0){
                cout << dq.front();
                dq.pop_front();
            }

            else{
                cout << dq.back();
                dq.pop_back();
            }
            if(cnt==size-1) cout << "]";
            else cout << ','; 
            cnt++;
        }
        if(flag==0 && size==0) cout << "[]";
        cout << '\n';
    }
}