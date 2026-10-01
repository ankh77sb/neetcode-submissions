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
    int dfs(TreeNode* root,int& count, int k) {
        if(root == nullptr) return -1;
        int x = dfs(root->left, count, k);
        if(x!=-1) return x;
        count++; 
        if(count == k) return root->val;
        x = dfs(root->right, count, k);
        if(x!=-1) return x;
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return dfs(root, count, k);
    }
};
