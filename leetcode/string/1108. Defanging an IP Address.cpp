class Solution {
public:
    string defangIPaddr(string address) {
        string defanged;
        for(auto a : address) {
            if(a=='.') defanged += "[.]";
            else defanged += a;
        }
        return defanged;
    }
};