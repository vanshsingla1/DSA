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
    void inorder(TreeNode* root, int &res, int &count, int k) {
        if(root == NULL)
        return;
        inorder(root->left,res,count,k);
        count++;
        if(k == count) {
            res = root->val;
            return;
        }
        inorder(root->right,res,count,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        //inorder traversal kro and return the result when count == k
        int res = -1;
        int count = 0;
        inorder(root,res,count,k);
        return res;
    }
};