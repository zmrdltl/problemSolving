import java.util.*;

class Solution {
    public int solution(int k, int m, int[] score) {
        int answer = 0;
        Integer[] integerArr = Arrays.stream(score).boxed().toArray(Integer[]::new);
        Arrays.sort(integerArr, Collections.reverseOrder());
        for (int i = 0; i < integerArr.length; i += m) {
            if (i + m - 1 < integerArr.length) {
                answer += integerArr[i + m - 1] * m;
            }
        }
        return answer;
    }
}
