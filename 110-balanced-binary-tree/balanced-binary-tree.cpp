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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        return 0;
        int r1=maxDepth(root->left);
        if(r1 == -1)
        return -1;
        int r2=maxDepth(root->right);
        if(r2 == -1)
        return -1;
        if(abs(r1-r2) > 1)
        return -1;
        return (max(r1,r2)+1);
    }
    bool isBalanced(TreeNode* root) {
        return (maxDepth(root) != -1);
    }
};