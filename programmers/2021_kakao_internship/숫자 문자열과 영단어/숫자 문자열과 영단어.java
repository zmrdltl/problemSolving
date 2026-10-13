import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        Map <String, Integer> wordNumMap = new HashMap<>();
        wordNumMap.put("zero", 0);
        wordNumMap.put("one", 1);
        wordNumMap.put("two", 2);
        wordNumMap.put("three", 3);
        wordNumMap.put("four", 4);
        wordNumMap.put("five", 5);
        wordNumMap.put("six", 6);
        wordNumMap.put("seven", 7);
        wordNumMap.put("eight", 8);
        wordNumMap.put("nine", 9);

        String word = "";
        for (char ch: s.toCharArray()) {
            if ('0' <= ch && ch <= '9') {
                answer = answer * 10 + (ch - '0');
            } else {
                word += ch;
                Integer number = wordNumMap.get(word);
                if (number != null) {
                    answer = answer * 10 + number;
                    word = "";
                }
            }
        }
        return answer;
    }
}
