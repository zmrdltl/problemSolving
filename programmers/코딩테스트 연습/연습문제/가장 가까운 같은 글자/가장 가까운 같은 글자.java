import java.util.*;

class Solution {
    public int[] solution(String s) {
        int[] answer = new int[s.length()];
        Map<Character, Integer> m = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            Character ch = s.charAt(i);
            if (!m.containsKey(ch)) {
                answer[i] = -1;
            } else {
                answer[i] = i - m.get(ch);
            }
            m.put(ch, i);
        }

        return answer;
    }
}
