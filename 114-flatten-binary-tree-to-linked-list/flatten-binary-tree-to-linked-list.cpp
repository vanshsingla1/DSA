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
    void flatten(TreeNode* root) {
        if(root==NULL)
        return;
        stack<TreeNode *>stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode* ptr=stk.top();
            stk.pop();
            if(ptr->right!=NULL)
            stk.push(ptr->right);
            if(ptr->left!=NULL)
            stk.push(ptr->left);
            // now join the right and remove its connection with left
            ptr->left = NULL;
            if(!stk.empty())
            ptr->right = stk.top();
            else
            ptr->right = NULL;
        }
    }
};