struct Answer {
    char character;
    int duration;
};

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        Answer ans = {keysPressed[0], releaseTimes[0]};
        int size = releaseTimes.size();
        for(int i = 1; i < size; i++) {
            int duration = releaseTimes[i] - releaseTimes[i-1];
            char curChar = keysPressed[i];
            if (ans.duration <= duration) {
                if(ans.duration == duration) {
                    ans.character = max(ans.character, curChar);
                } else {
                    ans.character = curChar;
                }
                ans.duration = duration;
            }
        }
        return ans.character;
    }
};