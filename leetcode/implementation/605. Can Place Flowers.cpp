class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int plantedCnt = 0;
        vector <int> fb = {0};
        fb.insert(fb.end(), flowerbed.begin(), flowerbed.end());
        fb.push_back(0);
        for(int i = 1; i < fb.size()-1; i++) {
            if(fb[i]) continue;
            if(!fb[i-1] && !fb[i+1]) {
                plantedCnt++;
                fb[i] = 1;
            }
        }
        return plantedCnt >= n;
    }
};