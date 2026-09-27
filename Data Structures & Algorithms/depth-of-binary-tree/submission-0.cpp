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
    int maxDepth(TreeNode* root) {

        if(root == nullptr) return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        int res = 0;

        while(!st.empty()) {
            pair<TreeNode*, int> temp = st.top();
            st.pop();
            TreeNode* node = temp.first;
            int depth = temp.second;

            if(node!=nullptr) {
                res = max(res, depth);
                if(node->left) {
                    st.push({node->left, depth + 1});
                }
                if(node->right) {
                    st.push({node->right, depth + 1});
                }
            }
        }

        return res;
    }
};
