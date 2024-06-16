class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue <int> studentQueue;
        for(auto s : students) {
            studentQueue.push(s);
        }
        
        int moved = 0;
        int idx = 0;

        while(studentQueue.size() && moved < studentQueue.size()) {
            if(studentQueue.front() == sandwiches[idx]) {
                studentQueue.pop();
                moved = 0;
                idx++;
            } else {
                studentQueue.push(studentQueue.front());
                studentQueue.pop();
                moved++;
            }
        }
        return studentQueue.size();
    }
};