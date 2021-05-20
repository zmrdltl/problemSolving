#include <bits/stdc++.h>
#define INF 0x3f3f3f3f;
using namespace std;
using pii = pair<int,int>;
int n, m, fuel, ans;
int board[21][21], ck[21][21];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int taxiRow, taxiCol;
struct Customer { int startRow, startCol, endRow, endCol, distance; };
vector <Customer> customerInfo;
int dist[21][21];

bool cmp(Customer a, Customer b){
    if(a.distance == b.distance){
        if(a.startRow == b.startRow)
            return a.startCol < b.startCol;
        return a.startRow < b.startRow;
    }
    return a.distance < b.distance;
}

void updateDistance(){
    memset(ck,0,sizeof(ck));
    memset(dist,0,sizeof(dist));
    queue <pii> q;
    q.push({taxiRow,taxiCol});
    ck[taxiRow][taxiCol] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(1 > nx || nx > n || 1 > ny || ny > n) continue;
            if(board[nx][ny] == 1 || ck[nx][ny]) continue;
            ck[nx][ny] = 1;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx,ny});
        }
    }
}

void updateCustomerInfo(int option = 0){
    if(!option){
        for(int i = 0; i < customerInfo.size(); i++)
            customerInfo[i].distance = dist[customerInfo[i].startRow][customerInfo[i].startCol];
        sort(customerInfo.begin(),customerInfo.end(),cmp);
    }
    else{
        for(int i = 0; i < customerInfo.size(); i++)
            customerInfo[i].distance = dist[customerInfo[i].endRow][customerInfo[i].endCol];
    }
}

int goToDestination(int option = 0){
    updateDistance();
    if(!option) updateCustomerInfo();
    else updateCustomerInfo(1);
    
    if(!customerInfo[0].distance) {
        if(taxiRow != customerInfo[0].startRow || taxiCol != customerInfo[0].startCol)
            return -1;
    }
    if(customerInfo[0].distance > fuel) return -1;

    if(!option){
        taxiRow = customerInfo[0].startRow;
        taxiCol = customerInfo[0].startCol;
    }

    else{
        taxiRow = customerInfo[0].endRow;
        taxiCol = customerInfo[0].endCol;
    }

    
    fuel -= customerInfo[0].distance; 
    if(option == 1){
        fuel += customerInfo[0].distance * 2;
    }
    return 1;
}

int main(){
    cin >> n >> m >> fuel;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> board[i][j];
        }
    }
    cin >> taxiRow >> taxiCol;
    for(int i = 1; i <= m; i++){
        Customer customer;
        cin >> customer.startRow >> customer.startCol >> customer.endRow >> customer.endCol;
        customerInfo.push_back(customer);
    }
    while(customerInfo.size()){
        if(goToDestination() == -1){ cout << -1; return 0; }
        if(goToDestination(1) == -1){ cout << -1; return 0; };
        customerInfo.erase(customerInfo.begin());
    }
    cout << fuel;
}