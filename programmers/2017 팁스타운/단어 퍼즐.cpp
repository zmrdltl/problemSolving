#include <bits/stdc++.h>
using namespace std;

//�־��� ������ ������� -1�� return
// t�� 1�̻� 20,000 ����

int dp[20000];

int solution(vector<string> strs, string t){
	int answer = 0;
	for (int idx = 0; idx < t.size(); idx++) {

		char c = t[idx];
        dp[idx] = t.size() + 1;
		for (int i = 0; i < strs.size(); i++) {
			bool same = true;
			int length = strs[i].size() - 1;
			if (strs[i][length] != c) continue;
            //������� ���ڿ��� ������ ��
			for (int k = 0; k <= length; k++) { 
				if (t[idx - k] != strs[i][length - k]) { same = false; break; }
			}
            if(same == false) continue;
			if (idx - length - 1 == -1) dp[idx] = 1;
			else {
				if (dp[idx - length - 1] + 1 < dp[idx]) 
					dp[idx] = dp[idx - length - 1] + 1;
			}
		}
    }


	answer = dp[t.size() - 1];
    if(answer >= t.size() + 1) return -1;
	return answer;
}
