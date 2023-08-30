class Solution {
public:
    int gcd(int a, int b) {
        if(!b) return a;
        return gcd(b, a%b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        map <int,int> m;
        for(auto d : deck) {
            m[d]++;
        }
        int g = m.begin()->second;
        for(auto el : m) {
            g = gcd(g, el.second);
        }
        return g > 1;
    }
};