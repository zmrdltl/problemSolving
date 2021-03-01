#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<map>
// #include<set>
using namespace std;
int d[101];
int num[2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n,0);
        map<int,int> m;
        map<int,int>::iterator it;
        m[5001]=1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>1){
                m[i]=1;
            }
        }
        long long cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==1)continue;
            if(a[i]>n-i){
                cnt+=a[i]-(n-i);
                a[i]=n-i;
            }
            while(a[i]>1){
                cnt++;
                int cur=i+a[i];
                a[i]--;
                while(cur<n){
                    int nextStep = a[cur];
                    if(nextStep>1){
                        a[cur]--;
                        if(a[cur]==1){
                            m.erase(cur);
                        }
                        cur+=nextStep;
                    }else{
                        it = m.lower_bound(cur);
                        cur = it->first;
                        // printf("i : %d cur : %d it : %d\n",i,cur , nextStep);
                    }
                }
            }
            m.erase(i);
        }
        cout<<cnt<<"\n";
    }

}