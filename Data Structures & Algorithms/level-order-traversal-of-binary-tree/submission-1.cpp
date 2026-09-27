/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> res;
        if(root == nullptr) return res;
        stack<pair<TreeNode*,int>> st;
        st.push({root, 0});
        
        while(!st.empty()) {
            pair<TreeNode*, int> t = st.top();
            st.pop();
            if(t.second >= res.size()) {
                res.push_back({t.first->val});
            } else {
                res[t.second].push_back(t.first->val);   
            }
            if(t.first->right)
                st.push({t.first->right, t.second + 1});
            if(t.first->left)
                st.push({t.first->left, t.second + 1});

        }

        return res;
    }
};
