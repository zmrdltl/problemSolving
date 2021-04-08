#include <bits/stdc++.h>

using namespace std;
vector<string> tmp;

int getMenuCnt(string s, vector <string> &orders){
    int cnt = 0;
    for(int i = 0; i < orders.size(); i++){
        int pivot = 0;
        for(int j = 0; j < orders[i].size(); j++)
            if(orders[i][j] == s[pivot]) 
                pivot++;
        if(pivot == s.size()) cnt++;
    }
    return cnt;
}

vector <string> getMaxOrderedMenuList(vector <string> &orders){
    int maxMenuCnt = 0;
    vector<string> maxMenuList;
    for(auto &t : tmp) maxMenuCnt = max(maxMenuCnt, getMenuCnt(t,orders));

    for(auto &t : tmp)
        if(maxMenuCnt>=2 && getMenuCnt(t,orders) == maxMenuCnt) 
            maxMenuList.push_back(t);
    return maxMenuList;
}

void backTracking(int depth,int idx, int m, string s, string candidates){
    if(depth == m) { tmp.push_back(s); return; }
    for(int i = idx; i < candidates.size(); i++)
        backTracking(depth + 1, i + 1, m, s+candidates[i],candidates);
}

string getCandidatesString(vector<string> orders){
    map <char,int> m;
    string candidates = "";
    for(auto &o : orders)
        for(int i = 0; i < o.size(); i++)
            m[o[i]]++;
    for(auto &a : m) 
        if(a.second >= 2) 
            candidates += a.first;
    return candidates;
}

void sortOrders(vector <string> &orders){
    for(auto &o : orders){
        vector<char> tmp;
        for(int i = 0; i < o.size(); i++) tmp.push_back(o[i]);
        sort(tmp.begin(),tmp.end());
        string s = "";
        for(auto &t : tmp) s += t;
        o = s;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector <string> answer;
    sortOrders(orders);
    string candidates = getCandidatesString(orders);

    for(auto &c : course){
        tmp.clear();
        backTracking(0,0,c,"",candidates);
        vector <string> maxOrderedList = getMaxOrderedMenuList(orders);
        for(auto &mo : maxOrderedList) answer.push_back(mo);
    }

    sort(answer.begin(),answer.end());
    return answer;
}

// int main(){
//     vector <string> answer;
//     answer = solution({"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"},{2,3,4});
//     for ( auto &a : answer) cout << a << ' ';
// }