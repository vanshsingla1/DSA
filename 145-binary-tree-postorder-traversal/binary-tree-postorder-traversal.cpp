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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;

        if(root == NULL)
        return res;
        
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode *ptr = stk.top();
            stk.pop();
            res.push_back(ptr->val);
            
            if(ptr->left != NULL)
            stk.push(ptr->left);
            if(ptr->right != NULL)
            stk.push(ptr->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};