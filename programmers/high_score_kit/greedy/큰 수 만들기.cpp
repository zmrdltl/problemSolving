#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int size = number.size() - k;
    int pivot = 0;

    for(int i = 0; i < size; i++){
        int bigIdx = pivot;        
        char bigchar = number[pivot];
        for(int j = pivot; j <= k+i; j++){
            if(bigchar < number[j]){
                bigchar = number[j];
                bigIdx = j;
            }
        }
        answer += bigchar;
        pivot = bigIdx + 1;
    }
   
    return answer;
}