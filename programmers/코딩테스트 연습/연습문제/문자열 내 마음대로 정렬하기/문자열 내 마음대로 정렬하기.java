import java.util.*;

class Solution {
    public String[] solution(String[] strings, int n) {
        Arrays.sort(strings, (String s1, String s2) -> {
            int res = Character.compare(s1.charAt(n), s2.charAt(n));
            if (res == 0) {
                return s1.compareTo(s2);
            }
            return res;
        });
        return strings;
    }
}
