class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int> st;
        int n = operations.size();

        for(int i = 0; i < n; i++) {
            if(operations[i] == "+") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.push(x);
                st.push(x+y);
            } else if(operations[i] == "D") {
                int x = st.top();
                st.push(2 * x);
            } else if(operations[i] == "C") {
                st.pop();
            } else st.push(stoi(operations[i]));
        }

        int res = 0;

        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
    }
};