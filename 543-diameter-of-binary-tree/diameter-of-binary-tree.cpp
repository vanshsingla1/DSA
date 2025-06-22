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
    int res = 0;
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        return 0;
        if(root->left==NULL && root->right==NULL)
        return 1;
        int r1=maxDepth(root->left);
        int r2=maxDepth(root->right);
        res = max(res,r1+r2);
        return (max(r1,r2)+1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return res;
    }
};