#include <bits/stdc++.h>
using namespace std;
string s, nemo = "nemo";
int main(){
    while(1){
        getline(cin,s);
        if(s == "EOI") break;
        for(int i = 0; i < s.size(); i++){
            if('A' <= s[i] && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
        }
        cout << (search(s.begin(), s.end(), nemo.begin(), nemo.end(),
			[](const char& c1, const char& c2) {return toupper(c1) == toupper(c2); }) != s.end() ? "Found\n" : "Missing\n");
	}
}