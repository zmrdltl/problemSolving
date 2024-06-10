class Solution {
public:
    int numberOfMatches(int n) {
        int teams = n;
        int matches = 0;
        while(teams > 1) {
            int roundMatch = teams / 2;
            matches += roundMatch;
            teams = roundMatch + teams % 2;
        }
        return matches;
    }
};