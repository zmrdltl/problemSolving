import java.util.*;

class Solution {
    public int[] solution(int[] answers) {
        int[] answer = {};
        ArrayList<Integer> winners = new ArrayList<>();
        int[] corrected = { 0, 0, 0 };
        int[] personA = { 1, 2, 3, 4, 5 };
        int[] personB = { 2, 1, 2, 3, 2, 4, 2, 5 };
        int[] personC = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
        for (int i = 0; i < answers.length; i++) {
            int currentAns = answers[i];
            if (personA[i % 5] == currentAns) {
                corrected[0]++;
            }
            if (personB[i % 8] == currentAns) {
                corrected[1]++;
            }
            if (personC[i % 10] == currentAns) {
                corrected[2]++;
            }
        }
        int maxCorrected = 0;
        for (int i = 0; i < 3; i++) {
            maxCorrected = Math.max(corrected[i], maxCorrected);
        }
        for (int i = 0; i < 3; i++) {
            if (corrected[i] == maxCorrected) {
                winners.add(i + 1);
            }
        }
        answer = new int[winners.size()];
        for (int i = 0; i < winners.size(); i++) {
            answer[i] = winners.get(i);
        }
        return answer;
    }
}
