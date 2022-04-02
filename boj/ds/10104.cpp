#include <bits/stdc++.h>
using namespace std;

int k,m;
vector <int> friends, removal, isRemoved;

int main(){
    cin >> k >> m;

    friends.resize(k+1);
    removal.resize(m);
    isRemoved.resize(k+1);

    for(int i = 0; i < m; i++) cin >> removal[i];
    for(int i = 1; i <= k; i++) friends[i] = i;

    for(auto re : removal){
        int sz = friends.size();
        vector <int> updatedFriends;

        for(int i = 1; re * i <= sz; i++) isRemoved[friends[re*i]] = 1;

        for(int i = 0; i <= k; i++)
            if(!isRemoved[i]) 
                updatedFriends.push_back(i);

        friends = updatedFriends;
    }

    for(int i = 1; i < friends.size(); i++) cout << friends[i] << '\n';
}