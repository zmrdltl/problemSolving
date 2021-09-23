#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;
using pii = pair<int,int>;
// town max
// dist max ; 10^5 < 2^17
const int DMAX = 17;

int N, K, Depth[100001];
// parent[i][k] : i��  2^k ��° �����ȣ
int parent[100001][DMAX+1];
// Value[i][k] : i�� 2^k��° ��������� pair< ��������, ū���� >
pii Value[100001][DMAX+1];
// < ����� ���� , ������� > 
vector<pii> arr[100001];
// �� ������ depth �����ϴ� �Լ�
void MakeTree(int curr){
	for(auto child: arr[curr]){		
		int town = child.first;		
		int BaseV = child.second;
		//  �̹� ���ƺ� ���ô� �н� 
		if(Depth[town]!=0) continue;
		Depth[town] = Depth[curr]+1;
		// 2^0 ��° �θ� ���� 
		parent[town][0] = curr;
		// �ٷ� �θ���� �������� = ū���� 
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
    // 1�� root �� depth[1] = 1 �� ����
    Depth[1] = 1;
    // �� ��� depth ����
    MakeTree(1);
    // parent[i][k] �� Value[i][k] ���ϱ�
    for(int k=0; k<=DMAX; ++k){
        for(int i=2; i<=N; ++i){
            int Father = parent[i][k];
            if(Father){
                parent[i][k+1] = parent[Father][k];
                // �������� ������Ʈ
                Value[i][k+1].first = min(Value[i][k].first, Value[Father][k].first);
                // ū���� ������Ʈ
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