class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int maxPopulation = 0;
        int ans = 1950;
        int populationChanges[101] = {0};
        for (auto l : logs) {
            int birth = l[0];
            int death = l[1];
            populationChanges[birth - 1950]++;
            populationChanges[death - 1950]--;
        }
        int currentPopulation  = 0;
        for (int i = 0; i <= 100; i++) {
            currentPopulation += populationChanges[i];
            if (currentPopulation > maxPopulation) {
                ans = i + 1950;
                maxPopulation = currentPopulation;
            }
        }
        return ans;
    }
};