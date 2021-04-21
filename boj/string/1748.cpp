#include<iostream>
#include<string>
using namespace std;
int ans, margin, behind = 9, after = 1;

int main(){
	string n;
	cin >> n;
	for (int i = 1; i < n.size(); i++){
		ans += behind * i;
		behind *= 10;
		after *= 10;
	}
    margin = (stoi(n) - after + 1) * n.size();
	cout << ans + margin << endl;
}