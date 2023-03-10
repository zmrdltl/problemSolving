class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i = 1; i<=n; i++) {
            string a;
            if(i % 3 && i % 5) {
                a += to_string(i);
            }
            else {
                if(i % 3 == 0) a += "Fizz";
                if(i % 5 == 0) a += "Buzz";
            }
            ans.push_back(a);
        }
        return ans;
    }
};