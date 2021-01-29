#include <bits/stdc++.h>
using namespace std;

string bracket; 
stack <char>st;
int tmp = 1;
int answer = 0;
int valid = 1;

int main(){
	cin >> bracket;
	for (int i = 0; i < bracket.size(); i++){
        if (bracket[i] == ')' && (st.empty() || st.top() != '(')) {valid = 0; break;}
		if (bracket[i] == ']' && (st.empty() || st.top() != '[')) {valid = 0; break;}

		if (bracket[i] == '('){
			tmp = tmp * 2;
			st.push('(');
		}
		if (bracket[i] == '['){
			tmp = tmp * 3;
			st.push('[');
		}
		if (bracket[i] == ')'){
			if (bracket[i - 1] == '(') //if not nested bracket
				answer = answer + tmp;
			st.pop();
			tmp = tmp / 2;
		}
		if (bracket[i] == ']'){
			if (bracket[i - 1] == '[')
				answer = answer + tmp;
			st.pop();
			tmp = tmp / 3;
		}
	}
	if (!valid || st.size())
		cout << '0' << endl;
	else 
		cout << answer << endl;
}