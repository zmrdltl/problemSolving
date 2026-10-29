class Solution {
    public int getDivisor(int number) {
        int cnt = 1;
        for (int i = 2; i * i <= number; i++) {
            int exponent = 0;
            while (number % i == 0) {
                number /= i;
                exponent++;
            }
            cnt *= exponent + 1;
        }
        if (number > 1) {
            return cnt * 2;
        }
        return cnt;
    }

    public int solution(int number, int limit, int power) {
        int answer = 0;
        for (int i = 1; i <= number; i++) {
            int divisor = getDivisor(i);
            if (divisor > limit) {
                answer += power;
            } else {
                answer += divisor;
            }
        }
        return answer;
    }
}
