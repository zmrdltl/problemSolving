#include <bits/stdc++.h>
using namespace std;
int n;
struct Student { string name; int korean, english, math; };
vector <Student> v;

bool cmp(Student &a, Student &b){
    if(a.korean == b.korean){
        if(a.english == b.english) {
            if(a.math == b.math) return a.name < b.name;
            return a.math > b.math;
        }
        return a.english < b.english;
    }
    return a.korean > b.korean;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string name;
        int korean, english, math;
        cin >> name >> korean >> english >> math;
        v.push_back({name,korean,english,math});
    }
    sort(v.begin(),v.end(),cmp);

    for(auto &s : v) cout << s.name << '\n';
}