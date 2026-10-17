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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            if(p.second >= res.size()) {
                res.push_back(p.first->val);
            } else res[p.second] = p.first->val;
            if(p.first->left)
            q.push({p.first->left, p.second + 1});
            if(p.first->right)
            q.push({p.first->right, p.second + 1});
        }

        return res;
    }
};
