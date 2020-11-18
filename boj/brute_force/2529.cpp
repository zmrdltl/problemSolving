#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int k;
char sign[10];
string ans;
vector<string> result;
bool check[10];
void solve(string ans, int cnt){
	if (cnt == k) {  
		result.push_back(ans);
		return;
	}
	int temp = ans[cnt] - '0'; 
    if(sign[cnt]=='<'){
        for (int i = 0; i < 10; ++i) {
            if (temp >= i) continue;
            if (!check[i]) {  
                check[i] = true;
                ans += (i + '0');
                solve(ans, cnt + 1);
                check[i] = false;
                ans.pop_back();
		    }
	    }
    }
    else{
        for (int i = 0; i < 10; ++i) {
            if (temp <= i) continue;
            if (!check[i]) {  
                check[i] = true;
                ans += (i + '0');
                solve(ans, cnt + 1);
                check[i] = false;
                ans.pop_back();
		    }
	    }
    }
	
}

int main(){
	cin >> k;
	for (int i = 0; i < k; ++i){
		cin >> sign[i];
	}
	for (int i = 0; i < 10; ++i){
		if (!check[i]) {
			check[i] = true;
			ans += (i + '0');
			solve(ans, 0);  // 0부터 ~ 9까지 한 숫자를 먼저 고른다.
			check[i] = false;
			ans.pop_back();
		}
	}
    cout << result[result.size()-1] << '\n' << result[0];
}