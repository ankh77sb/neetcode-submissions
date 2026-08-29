class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;
        path += "/";
        int n = path.size();
        string prev = "";

        for(int i = 0 ; i < n ; i++) {
            if(path[i] == '/') {
                if(prev.size() == 0 || prev == ".") {
                    prev = "";
                    continue;
                } else if(prev == "..") {
                    prev = "";
                    if(!st.empty()) st.pop();
                } else {
                    st.push(prev);
                    prev = "";
                }
            } else {
                prev += path[i];
            }
        }

        if(prev.size() > 0)  {st.push(prev); prev = "";}
        string res = "";
        
        while(!st.empty()) {
            string curr = st.top();
            reverse(curr.begin(), curr.end());
            st.pop();
            curr += "/";
            res += curr; 
        }

        reverse(res.begin(), res.end());
        return res.size() > 0? res: "/";
        
    }
};