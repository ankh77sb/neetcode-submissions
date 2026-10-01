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
    int maxsum = INT_MIN;
    int dfs(TreeNode* root) {
        if(root == nullptr) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        maxsum = max({maxsum, root->val + max(l, 0) + max(r, 0)});
    
        return max({l + root->val, r + root->val, root->val});
    }

public:
    int maxPathSum(TreeNode* root) {
        maxsum = max(dfs(root), maxsum);
        return maxsum;
    }
};
