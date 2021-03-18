#include <bits/stdc++.h>
using namespace std;
int n,k;
//위층은 0 ~ n-1까지의 벨트
//아래층은 n ~ 2*n-1까지의 벨트
struct square{
    int durability,robot;
};

void processOne(vector <square> &belt){
    vector <square> tmp(2*n);
    tmp[0].durability = belt[2*n-1].durability;
    tmp[0].robot = belt[2*n-1].robot;
   
    for(int i = 0; i < 2 * n - 1; i++){
        tmp[i+1].durability = belt[i].durability;
        tmp[i+1].robot = belt[i].robot;
    }
    belt = tmp;
    if(belt[n-1].robot) belt[n-1].robot = 0;
}
    

void processTwo(vector <square> &belt){
    vector<int>moved(2*n);
    //n-1칸의 로봇은 이미 내린 상태 0 ~ n-1까지 옮겨주면됨
    for(int i = n-2; i >= 0; i--){
        //다음칸에 내구도 참이고 로봇이 없으면 옮겨줌.
        if(belt[i].robot && !belt[i+1].robot && belt[i+1].durability){
            belt[i+1].robot = 1;
            belt[i].robot = 0;
            if(belt[i+1].durability) belt[i+1].durability--;
        }
    }
    belt[n-1].robot = 0;
};

void processThree(vector <square> &belt){
    if(belt[0].durability && !belt[0].robot) {
        belt[0].robot = 1;
        belt[0].durability--;
    }
};

int getZeroDuration(vector <square> &belt){
    int cnt = 0;
    for(auto b : belt){
        if(!b.durability) cnt++;
    }
    return cnt;
}

void print(vector <square> &belt){
    cout << "belt : ";
    for(int i  =0; i < 2*n; i++){
        cout << belt[i].durability << ' ';
    }
    cout << '\n';
    cout << "robot : ";
    for(int i  =0; i < 2*n; i++){
        cout << belt[i].robot << ' ';
    }
    cout << '\n';
    cout << '\n';
}
int beltProcess(vector <square> &belt,int k){
    int processNum = 0;
    while(1){
        processNum++;
        processOne(belt); //회전
        processTwo(belt);//로봇 이동
        processThree(belt);//로봇 올리기 
        if(getZeroDuration(belt) >= k) break;//0내구도가 k개 이상이면
    }
    return processNum;
}

int main(){
    cin >> n >> k;
    vector <square> belt(2*n);
    for(int i = 0; i < 2 * n; i++) {
        int d;
        cin >> d;
        belt[i] = {d,0};
    }
    cout << beltProcess(belt,k) <<'\n';
}