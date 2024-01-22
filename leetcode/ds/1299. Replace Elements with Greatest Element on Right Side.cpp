using pii = pair<int,int>;
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector <int> ans;
        priority_queue <int, vector<int>, less<int>> pq;
        map<int,int> arrNumIndex;

        for(int i = 0; i < arr.size(); i++) {
            pq.push({arr[i]});
            arrNumIndex[arr[i]] = i;
        }

        for(int i = 0; i < arr.size(); i++) {
            while(pq.size() && arrNumIndex[pq.top()] <= i) pq.pop();

            if (i < arrNumIndex[pq.top()]) {
                ans.push_back(pq.top());
            }
        }
        ans.push_back(-1);
        return ans;
    }
};