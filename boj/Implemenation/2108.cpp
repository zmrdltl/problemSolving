#include <bits/stdc++.h>
using namespace std;
int num[500001];
int n;

double getAvg(){
    double sum = 0;
    for(int i = 1; i <= n; i++) sum += num[i];
    return round(sum / (double)n);
}

int getMiddleValue(){
    sort(num+1, num+n+1);
    return num[n/2+1];
}

int getSecondFrequencyValue(){
    map <int,int> m;
    for(int i = 1; i <= n; i ++){
        if(m[num[i]]) m[num[i]]++;
        else m[num[i]] = 1;
    }
    int maxFrequency = 0;

    vector <int> f;
    for(auto p:m){
        if(maxFrequency < p.second){
            maxFrequency = p.second; //가장 자주 나오는 빈도수
        }
    }

    for(auto p : m){
        if(maxFrequency==p.second){
            f.push_back(p.first);
        }
    }

    sort(f.begin(),f.end());
    if(f.size()==1) return f[0];
    return f[1];
}

int getMinMaxGap(){
    int minVal = 0x7f7f7f7f;
    int minIdx = 0;
    int maxVal = -0x7f7f7f7f;
    int maxIdx = 0;
    for(int i = 1; i<=n; i++){
        if(maxVal < num[i]){
            maxVal = num[i];
            maxIdx = i;
        }
        if(minVal > num[i]){
            minVal = num[i];
            minIdx = i;
        }
    }
    return maxVal - minVal;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> num[i];
    cout << getAvg() <<'\n';
    cout << getMiddleValue() <<'\n';
    cout << getSecondFrequencyValue() <<'\n';
    cout << getMinMaxGap() <<'\n';
}