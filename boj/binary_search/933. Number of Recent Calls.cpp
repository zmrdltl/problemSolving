class RecentCounter {
public:
    vector <int> requests;
    
    int ping(int t) {
        requests.push_back(t);
        auto idx = lower_bound(requests.begin(), requests.end(), t-3000) - requests.begin();
        return requests.size() - idx;
    }
};
/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */