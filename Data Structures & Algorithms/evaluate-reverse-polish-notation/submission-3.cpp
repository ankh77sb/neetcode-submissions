class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<long long> st;

        for(int i = 0 ; i < tokens.size() ; i++) {
            if(tokens[i] == "+") {
                long long x = st.top(); st.pop();
                long long y = st.top(); st.pop();
                st.push(x+y);
            } else if(tokens[i] == "-") {
                long long x = st.top(); st.pop();
                long long y = st.top(); st.pop();
                st.push(y-x);
            }
            else if(tokens[i] == "*") {
                long long x = st.top(); st.pop();
                long long y = st.top(); st.pop();
                st.push(x*y);
            } else if(tokens[i] == "/") {
                long long x = st.top(); st.pop();
                long long y = st.top(); st.pop();
                st.push(y/x);
            } else st.push(stoi(tokens[i]));
        }

        return (int)st.top();
        
    }
};
