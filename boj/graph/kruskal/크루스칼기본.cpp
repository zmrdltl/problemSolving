//답은 123
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge{
public:
    int node[2];
    int distance;
    Edge(int a, int b, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    bool operator < (Edge &edge){
        return this->distance < edge.distance;
    }
};

int getParent(int parent[], int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent,parent[x]);
}

void unionParent(int parent[], int x, int y){
    int a = getParent(parent,x);
    int b = getParent(parent,y);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

vector <Edge> init(){
    vector<Edge> v;
    v.push_back(Edge(1,7,12));
    v.push_back(Edge(1,4,28));
    v.push_back(Edge(1,2,67));
    v.push_back(Edge(1,5,17));
    v.push_back(Edge(2,4,24));
    v.push_back(Edge(2,5,62));
    v.push_back(Edge(3,5,20));
    v.push_back(Edge(3,6,37));
    v.push_back(Edge(4,7,13));
    v.push_back(Edge(5,6,45));
    v.push_back(Edge(5,7,73));
    return v;
}

int main(){
    int n = 7; //정점개수
    int m = 11; //간선개수
    int parent[n];
    int cost = 0;

    vector <Edge> v = init(); 
   

    //간선 정렬
    sort(v.begin(),v.end());
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }


    //모든 간선에 대해 보는데 사이클 발생 안하면 union
    for(int i = 0; i < v.size(); i++){
        int firstParent = getParent(parent,v[i].node[0] - 1);
        int secondParent = getParent(parent,v[i].node[1] - 1);
        if(firstParent != secondParent) {
            unionParent(parent,firstParent,secondParent);
            cost += v[i].distance;
            cout << cost << ' ' << v[i].distance << '\n';
        }
    }
    cout << cost << '\n';

}