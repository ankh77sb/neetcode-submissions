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
    bool isSameTree(TreeNode* r1, TreeNode* r2) {
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;

        st1.push(r1);
        st2.push(r2);

        while(!st1.empty() && !st2.empty()) {
            TreeNode* t1 = st1.top();
            TreeNode* t2 = st2.top();
            st1.pop();
            st2.pop();

            if((t1 == nullptr) ^ (t2 == nullptr))
                return false;
            if(t1 == nullptr && t2 == nullptr)
                continue;
            if(t1->val != t2->val) return false;
            st1.push(t1->left);
            st2.push(t2->left);
            st1.push(t1->right);
            st2.push(t2->right);
        }

        return st1.empty() && st2.empty();
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        stack<TreeNode*> st;
    
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if(node == nullptr)
                continue;
            if(isSameTree(node, subRoot))
                return true;
            st.push(node->left);
            st.push(node->right);
        }
        
        return false;
    }
};
