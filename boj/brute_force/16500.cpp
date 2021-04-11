#include <bits/stdc++.h>
using namespace std;

string s; //만들어야할 문자열
int n;
vector<string> arr[26]; // 글자 t 로 끝나는 단어들 저장
int dp[101]; // dp[x] : x ~ 끝까지 채울 수 있는지 여부

int main() {
    cin >> s;
    cin >> n;
    for (int i = 0; i < n; ++i) { 
	    string ss;
	    cin >> ss;
	    int x = ss.back() - 'a'; 
	    arr[x].push_back(ss); 
    }
    dp[s.length()] = true;

    for (int i = s.length() - 1; i >= 0; i--) {
	    if (!dp[i + 1]) continue; 
	    int now = s[i] - 'a'; 
	    for (auto &el : arr[now]) {
		    int l = el.length(); 
		    int leftL = i - l + 1; 
		    if (leftL < 0) continue; 
            bool ok = true;
            for (int j = 0; j < l; ++j) {
                if (s[i - j] != el[(l - 1) - j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                dp[leftL] = true; 
            }
        }
    }
    if (dp[0]) cout << 1 << '\n';
    else cout << 0 << '\n';
}

