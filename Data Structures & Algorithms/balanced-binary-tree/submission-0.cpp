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
    bool res = true;
    int depth(TreeNode* root) {
        if(root == nullptr || res == false) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        res = res && (abs(left - right) <= 1);
        return max(1+left, 1+right);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        depth(root);
        return res;
    }
};
