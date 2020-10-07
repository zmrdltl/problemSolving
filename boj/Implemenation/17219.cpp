#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    map <string,string> siteInfo;
    int m,n;
    cin >> m >> n;
    for(int i  =0; i < m; i++){
        string site,password;
        cin >> site >> password;
        siteInfo[site] = password;
    }
    for(int i = 0; i < n; i++){
        string siteToFind;
        cin >> siteToFind;
        cout << siteInfo[siteToFind] << '\n';
    }
}