class Solution {
public:
    bool checkZeroOnes(string s) {
        int maxOneSegmentLength = 0, maxZeroSegmentLength = 0;
        int oneSeg = 0, zeroSeg = 0;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                maxOneSegmentLength = max(maxOneSegmentLength, oneSeg);
                oneSeg = 0;
                zeroSeg++;
            } else {
                maxZeroSegmentLength = max(maxZeroSegmentLength, zeroSeg);
                zeroSeg = 0;
                oneSeg++;
            }
        }
        maxOneSegmentLength = max(maxOneSegmentLength, oneSeg);
        maxZeroSegmentLength = max(maxZeroSegmentLength, zeroSeg);
        return maxOneSegmentLength > maxZeroSegmentLength;
    }
};