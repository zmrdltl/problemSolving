import java.math.BigDecimal;

class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        int plen = p.length();
        for(int i = 0; i <= t.length() - plen; i++) {
            String subString = t.substring(i, i+plen);
            if (new BigDecimal(subString).compareTo(new BigDecimal(p)) <= 0) {
                answer += 1;
            }
        }
        return answer;
    }
}