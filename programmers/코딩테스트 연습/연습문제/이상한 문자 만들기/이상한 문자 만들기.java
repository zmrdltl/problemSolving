class Solution {
    public String solution(String s) {
        String answer = "";
        int piv = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == ' ') {
                piv = 0;
                answer += ' ';
                continue;
            }
            if (piv % 2 == 0) {
                answer += Character.toUpperCase(ch);
            } else {
                answer += Character.toLowerCase(ch);
            }
            piv += 1;
        }

        return answer;
    }
}
