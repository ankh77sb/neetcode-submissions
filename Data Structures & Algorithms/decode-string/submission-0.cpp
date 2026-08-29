class Solution {
public:
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    string decodeString(string s) {
        
        int n = s.size();
        stack<char> st;

        for(int i = 0 ; i < n ; i++) {
            if(s[i] == ']') {
                string curr = "";
                while(!st.empty() && st.top() != '[') {
                    curr += st.top();
                    st.pop();
                }
                reverse(curr.begin(), curr.end());
                if(!st.empty()) st.pop();
                string number = "";
                while(!st.empty() && isDigit(st.top())) {
                    number += st.top();
                    st.pop();
                }
                reverse(number.begin(), number.end());
                int num = stoi(number);
                
                for(int i = 0; i < num; i++) {
                    for(int j = 0; j < curr.size(); j++)
                        st.push(curr[j]);
                }
            } else {
                st.push(s[i]);
            }
        }

        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};