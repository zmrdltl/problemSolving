class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int triples = 0, arrLength = arr.size();
        for(int i = 0; i < arrLength; i++) {
            for(int j = 0; j < arrLength; j++) {
                for(int k = 0; k < arrLength; k++) {
                    if (0 <= i && i < j && j < k && k < arrLength &&
                        abs(arr[i] - arr[j]) <= a &&
                        abs(arr[j] - arr[k]) <= b &&
                        abs(arr[i] - arr[k]) <= c
                    ) {
                        triples++;
                    }
                }
            }
        }
        return triples;
    }
};