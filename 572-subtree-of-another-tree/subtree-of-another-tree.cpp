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
    bool fun(TreeNode* root, TreeNode* subroot) {
        if(root == NULL && subroot == NULL) return true;
        if(root != NULL && subroot == NULL) return false;
        if(root == NULL && subroot != NULL) return false;
        if(root->val != subroot->val) return false;
        if(root->val == subroot->val) {
            return (fun(root->left,subroot->left) && fun(root->right,subroot->right));
        }
        return (fun(root->left,subroot) || fun(root->right,subroot));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        // traverse for each node
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *ptr = q.front(); q.pop();
            if(ptr->val == subRoot->val) {
                if(fun(ptr,subRoot)) return true;
            }
            if(ptr->left != NULL) q.push(ptr->left);
            if(ptr->right != NULL) q.push(ptr->right);
        }
        return false;
    }
};