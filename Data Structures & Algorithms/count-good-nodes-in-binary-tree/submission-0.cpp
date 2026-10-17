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
    int res = 0;
    void dfs(TreeNode* root, int maxtillnow) {
        if(root == nullptr) return;
        if(maxtillnow <= root->val) res++;
        dfs(root->left, max(maxtillnow, root->val));
        dfs(root->right, max(maxtillnow, root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        res = 0;
        dfs(root, -500);
        return res;
    }
};
