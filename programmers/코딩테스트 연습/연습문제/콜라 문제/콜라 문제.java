class Solution {
    public int solution(int a, int b, int n) {
        int answer = 0;
        while (n >= a) {
            int cola = n / a * b;
            answer += cola;
            n %= a;
            n += cola;
        }
        return answer;
    }
}
