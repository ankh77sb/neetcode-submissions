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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        stack<TreeNode*> p_stack;
        stack<TreeNode*> q_stack;

        p_stack.push(p);
        q_stack.push(q);

        while(!p_stack.empty() && !q_stack.empty()) {
            TreeNode* tmpp = p_stack.top();
            p_stack.pop();
            TreeNode* tmpq = q_stack.top();
            q_stack.pop();
            if(tmpp == nullptr && tmpq != nullptr)
                return false;
            if(tmpp != nullptr && tmpq == nullptr)
                return false;
            if(tmpp == nullptr && tmpq == nullptr)
                continue;
            if(tmpp->val != tmpq->val)
                return false;
            p_stack.push(tmpp->left);
            p_stack.push(tmpp->right);
            q_stack.push(tmpq->left);
            q_stack.push(tmpq->right);
        }
        
        return p_stack.empty() && q_stack.empty();
    }
};
