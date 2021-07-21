#include <bits/stdc++.h>
using ll = long long;
using namespace std;
map <ll,ll> roomMap;
ll find(ll x){
    if(!roomMap[x]) return x; //방이 비어있다면 x를 배정해준다
    return roomMap[x] = find(roomMap[x]);
}
vector<ll> solution(ll k, vector<ll> room_number) {
    roomMap.clear();
    vector <ll> answer;
    for(auto room : room_number){
        if(!roomMap[room]){
            answer.push_back(room);
            roomMap[room] = find(room + 1);
        }
        else{
            ll nroom = find(roomMap[room]);
            answer.push_back(nroom);
            roomMap[nroom] = find(nroom + 1);
        }
    }
    return answer;
}