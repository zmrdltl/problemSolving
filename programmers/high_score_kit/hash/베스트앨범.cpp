#include <bits/stdc++.h>

using namespace std;

bool desc(pair<int, int> a, pair<int, int> b) {
	// 각 원소들을 first에 관해서는 오름차순 정렬을, second에 관해서는 내림차순으로 정렬한다.
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int size = genres.size();
    map <string, vector<pair<int,int>>> record;
    map <string,int> played;
    map <int,string> totalPlayed;
    vector <string> bestPlayedgenre;
    for(int i = 0; i < size; i++)
        record[genres[i]].push_back({plays[i],i});
    
    for(auto r : record)
        for(auto rs : r.second)
            played[r.first] += rs.first; //각 장르별 총합 플레이 수 구하기
    
    for(auto p : played){
        totalPlayed[p.second] = p.first;
    }

    for(auto t = totalPlayed.rbegin(); t != totalPlayed.rend() ; t++)
        bestPlayedgenre.push_back(t->second); //1. 속한 노래가 많이 재생된 장르를 먼저 push

    for(auto bp : bestPlayedgenre){ 
        vector<pair<int,int>> genresSongList = record[bp];
        
        if(genresSongList.size()==1) { //해당 장르곡이 하나라면 그 곡의 index만 담기
            answer.push_back(genresSongList[0].second); 
            continue;
        } 
        
        sort(genresSongList.begin(),genresSongList.end(),desc); //해당 장르의 {플레이수, index}를 내림차순으로 정렬
        int cnt = 0;
        for(auto oneSong : genresSongList){ //2. 장르 내에서 많이 재생된 노래를 먼저 수록
            if(cnt == 2) break;
            answer.push_back(oneSong.second);
            cnt++;
        }
    }
    
    return answer;
}

int main(){
    vector<string> genres({"classic", "pop"});
    vector<int> plays({50,5000});
    vector <int> answer = solution(genres,plays);
    for(auto a : answer) cout << a << ' ';
}