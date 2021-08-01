#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n, m, parent[1001];
double ans;
struct Edge { int u, v; double w; };
vector <Edge> edges;
vector <pii> coords;

double getDistance(int x1, int y1, int x2, int y2){
    double X = abs(x1 - x2);
    double Y = abs(y1 - y2);
    return sqrt(abs(X*X+Y*Y));
}

bool cmp(Edge &a, Edge &b){
    return a.w < b.w;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main(){
    cin >> n >> m;
    coords.resize(n + 1);
    for(int i = 1; i <= n; i++) parent[i] = i;
    
    for(int i = 1,x,y; i <= n; i++){
        cin >> x >> y;
        coords[i] = {x,y};
    }

    for(int i = 1,x,y; i <= m; i++){
        cin >> x >> y;
        if(find(x) != find(y)){
            merge(x,y);
        }
    }


    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(find(i) != find(j)){
                int x1 = coords[i].first;
                int y1 = coords[i].second;
                int x2 = coords[j].first;
                int y2 = coords[j].second;
                edges.push_back({i,j, getDistance(x1,y1,x2,y2)});
            }
        }
    }

    sort(edges.begin(),edges.end(),cmp);

    for(int i = 0; i < edges.size(); i++){
        if(find(edges[i].u) != find(edges[i].v)){
            merge(edges[i].u,edges[i].v);
            ans += edges[i].w;
        }
    }
    
    printf("%.2f",ans);
}