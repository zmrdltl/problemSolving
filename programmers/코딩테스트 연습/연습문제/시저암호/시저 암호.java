class Solution {
    public String solution(String s, int n) {
        String answer = "";
        for (char ch : s.toCharArray()) {
            if ('a' <= ch && ch <= 'z') {
                answer += (char) ('a' + (ch - 'a' + n) % 26);
            } else if ('A' <= ch && ch <= 'Z') {
                answer += (char) ('A' + (ch - 'A' + n) % 26);
            } else {
                answer += ch;
            }
        }
        return answer;
    }
}
