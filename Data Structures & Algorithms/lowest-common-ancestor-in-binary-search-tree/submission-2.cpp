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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        if(root == nullptr) return nullptr;
        que.push(root);

        if(q->val < p->val) 
            swap(p, q);

        while(!que.empty()) {
            TreeNode* top = que.front();
            que.pop();
            if(p->val <= top->val && top->val <= q->val)
                return top;
            else if(p->val <= top->val && q->val <= top->val) {
                if(top->left)
                    que.push(top->left);
            } else {
                if(top->right)
                    que.push(top->right);
            }
        }

        return nullptr;
    }
};
