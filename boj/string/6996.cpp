#include <bits/stdc++.h>
using namespace std;
int * getAlpha(string &a, int arr[]){
    for(int i = 0; i < 26; i++) arr[i] = 0;
    for(int i = 0; i < a.size(); i++) arr[a[i]-'a']++;
    return arr;
}

bool isAnagram(int *alpha,int *alpha2){
    for(int i = 0; i < 26; i++)
        if(alpha[i] != alpha2[i]) 
            return false;
    return true;
}

int main(){
    int testCase;
    cin >> testCase;
    while(testCase--){
        string a,b;
        cin >> a >> b;
        int cnt[26], cnt2[26];
        int *alpha = getAlpha(a,cnt);
        int *alpha2 = getAlpha(b,cnt2);
        if(isAnagram(alpha,alpha2))
            cout << a << " & " << b << " are anagrams.\n";
        else
            cout << a << " & " << b << " are NOT anagrams.\n";
    }   
}