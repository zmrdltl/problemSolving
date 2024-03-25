class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int studentCnt = 0;
        int totalStudents = startTime.size();
        for(int i = 0; i < totalStudents; i++) {
            if(startTime[i] <= queryTime && queryTime <= endTime[i]) studentCnt++;
        }
        return studentCnt;
    }
};