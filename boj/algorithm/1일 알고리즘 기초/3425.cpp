#include <bits/stdc++.h>
#define ll long long
#define LIMIT 1000000000
using namespace std;
vector <string> operation;
vector <ll> nums;
stack <ll> st;
string op;
ll n,x, isError, num, c;

ll NUM(ll x){
    st.push(x);
    return 0;
}

ll POP(){
    if(st.empty()) return 1;
    st.pop();
    return 0;
}

ll INV(){
    if(st.empty()) return 1;
    ll tmp = st.top();
    st.pop();
    st.push(-tmp);
    return 0;
}

ll DUP(){
    if(st.empty()) return 1;
    st.push(st.top());
    return 0;
}

ll SWP(){
    if(st.size() < 2) return 1;
    ll tmp1 = st.top();
    st.pop();
    ll tmp2 = st.top();
    st.pop();
    st.push(tmp1);
    st.push(tmp2);
    return 0;
}

ll ADD() {
    if(st.size() < 2) return 1;
    ll tmp1 = st.top();
    st.pop();
    ll tmp2 = st.top();
    st.pop();
    st.push(tmp1 + tmp2);
    return 0;
}

ll SUB(){
    if(st.size() < 2) return 1;
    ll tmp1 = st.top();
    st.pop();
    ll tmp2 = st.top();
    st.pop();
    st.push(tmp2 - tmp1);
    return 0;
}

ll MUL(){
    if(st.size() < 2) return 1;
    ll tmp1 = st.top();
    st.pop();
    ll tmp2 = st.top();
    st.pop();
    st.push(tmp2 * tmp1);
    return 0;
}

ll DIV(){
    if(st.size() < 2) return 1;
    ll tmp1 = st.top();
    st.pop();
    ll tmp2 = st.top();
    st.pop();
    if(!tmp1) return 1;
    ll result = llabs(tmp2) / llabs(tmp1);
    if(tmp1 * tmp2 < 0) result *= -1;
    st.push(result);
    return 0;
}

ll MOD(){
    if(st.size() < 2) return 1;
    ll tmp1 = st.top();
    st.pop();
    ll tmp2 = st.top();
    st.pop();
    if(!tmp1) return 1;
    ll result = llabs(tmp2) % llabs(tmp1);
    if(tmp2 < 0) result *= -1;
    st.push(result);
    return 0;
}

int main(){
	while (1) {
        nums.clear();
		operation.clear();
		isError = 0;
        

		while (1) {
			cin >> op;
            if (op == "QUIT") return 0;
			if (op == "END") break;
			if (op == "NUM") cin >> x, nums.push_back(x);
			operation.push_back(op);
		}
 
		cin >> n;
        
		while (n--) {
			c = 0;
			cin >> num;
			st.push(num);
 
			for (ll i = 0; i < operation.size(); ++i) {
				if (operation[i] == "NUM") isError = NUM(nums[c++]);
				else if (operation[i] == "POP") isError = POP();
				else if (operation[i] == "INV") isError = INV();
				else if (operation[i] == "DUP") isError = DUP();
				else if (operation[i] == "SWP") isError = SWP();
				else if (operation[i] == "ADD") isError = ADD();
				else if (operation[i] == "SUB") isError = SUB();
				else if (operation[i] == "MUL") isError = MUL();
				else if (operation[i] == "DIV") isError = DIV();
				else if (operation[i] == "MOD") isError = MOD();
                
				if (!st.empty() && (llabs(st.top()) > LIMIT )) 
					isError = 1;

				if (isError) break;
			}

			if (isError || st.size() != 1) cout << "ERROR\n";
			else cout << st.top() << '\n';
			while (!st.empty()) st.pop();
		}

		cout << '\n';
	}
}
