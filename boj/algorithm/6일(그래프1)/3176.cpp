#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;
using pii = pair<int,int>;
// town max
// dist max ; 10^5 < 2^17
const int DMAX = 17;

int N, K, Depth[100001];
// parent[i][k] : i의  2^k 번째 조상번호
int parent[100001][DMAX+1];
// Value[i][k] : i의 2^k번째 조상까지의 pair< 작은길이, 큰길이 >
pii Value[100001][DMAX+1];
// < 연결된 도시 , 연결길이 > 
vector<pii> arr[100001];
// 각 노드들의 depth 설정하는 함수
void MakeTree(int curr){
	for(auto child: arr[curr]){		
		int town = child.first;		
		int BaseV = child.second;
		//  이미 돌아본 도시는 패스 
		if(Depth[town]!=0) continue;
		Depth[town] = Depth[curr]+1;
		// 2^0 번째 부모 저장 
		parent[town][0] = curr;
		// 바로 부모까지 작은길이 = 큰길이 
		Value[town][0] = pii(BaseV,BaseV);
		MakeTree(town); 
	}
}

int main(){
    fastio;

    cin >> N;
    for(int i=0; i<N-1; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        arr[a].push_back(pii(b,w));
        arr[b].push_back(pii(a,w));
    }
    // 1이 root 고 depth[1] = 1 로 설정
    Depth[1] = 1;
    // 각 노드 depth 설정
    MakeTree(1);
    // parent[i][k] 와 Value[i][k] 구하기
    for(int k=0; k<=DMAX; ++k){
        for(int i=2; i<=N; ++i){
            int Father = parent[i][k];
            if(Father){
                parent[i][k+1] = parent[Father][k];
                // 작은길이 업데이트
                Value[i][k+1].first = min(Value[i][k].first, Value[Father][k].first);
                // 큰길이 업데이트
                Value[i][k+1].second = max(Value[i][k].second, Value[Father][k].second);
            } 			
        }
    }
    cin >> K;
    for(int i=0; i<K; ++i){
        int a, b;
        cin >> a >> b;
        int mini = 1000000;
        int maxi = 0;
        if(Depth[a]<Depth[b]) swap(a,b);	
        int Diff = Depth[a] - Depth[b];
        int cnt = 0;
        while(Diff){
            if(Diff%2==1){
                mini = min(mini, Value[a][cnt].first);
                maxi = max(maxi, Value[a][cnt].second);
                a = parent[a][cnt];			
            } 
            Diff/=2;
            cnt++;
        }
        if(a!=b){
            for(int k=DMAX; k>=0; k--){
                if(parent[a][k]!=parent[b][k]){
                    mini = min(mini, Value[a][k].first);
                    maxi = max(maxi, Value[a][k].second);
                    a = parent[a][k];
                    mini = min(mini, Value[b][k].first);
                    maxi = max(maxi, Value[b][k].second);
                    b = parent[b][k];
                }
            }
            mini = min(mini, Value[a][0].first);
            maxi = max(maxi, Value[a][0].second);
            mini = min(mini, Value[b][0].first);
            maxi = max(maxi, Value[b][0].second);
            a=parent[a][0];
                    
        }
        cout << mini << ' ' << maxi << '\n';
    }

}