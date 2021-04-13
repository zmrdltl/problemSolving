#include <bits/stdc++.h>
using namespace std;
using psi = pair<string,int>;
int solution(int cacheSize, vector<string> cities) {
    if(!cacheSize) return cities.size() * 5;
    int answer = 0;
    deque <string> cache;

    for(auto &c: cities)
        for(int i = 0; i < c.size(); i++)
            if('A' <= c[i] && c[i] <= 'Z') 
                c[i] = c[i]-'A'+'a';

    for(int i = 0; i < cities.size(); i++){
        int hit = 0;
        //hit
        for(auto dq = cache.begin(); dq != cache.end(); dq++){
            if(*dq == cities[i]){
                string s = *dq;
                cache.erase(dq);
                cache.push_back(s);
                hit = 1;
                answer++;
                break;
            }
        }

        //miss
        if(!hit){
            if(cache.size() && cache.size() == cacheSize){
                cache.pop_front();
            }                
            cache.push_back(cities[i]);
            answer+=5;
        }
    }
    return answer;
}