import java.util.*;

class Solution {
    public boolean haveToSkip(String skip, Character c) {
        return skip.contains(String.valueOf(c));
    }

    public String solution(String s, String skip, int index) {
        StringBuilder sb = new StringBuilder();
        for (Character c : s.toCharArray()) {
            if (haveToSkip(skip, c)) {
                continue;
            }
            Character tmp = c;
            int cnt = 0;
            while (cnt < index) {
                tmp = (char) ((tmp - 'a' + 1) % 26 + 'a');
                if (haveToSkip(skip, tmp)) {
                    continue;
                }
                cnt++;
            }
            sb.append(tmp);
        }
        return sb.toString();
    }
}
