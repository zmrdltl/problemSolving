class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;
        stack <int> st;
        for(auto o : operations) {
            if(o == "+") {
                int prev = st.top();
                st.pop();
                int prevv = st.top();
                st.push(prev);
                st.push(prev + prevv);
            }
            else if(o == "D") {
                st.push(st.top() * 2);
            }
            else if(o == "C") {
                st.pop();
            }
            else {
                st.push(stoi(o));
            }
        }

        while(st.size()) {
            sum += st.top();
            st.pop();
        }
            
        return sum;
    }
};