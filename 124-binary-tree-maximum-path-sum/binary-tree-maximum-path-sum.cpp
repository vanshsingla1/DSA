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
    int maxDepth(TreeNode* root,int pathsum,int &res) {
        if(root==NULL)
        return 0;
        int r1=max(0,maxDepth(root->left,pathsum,res));
        int r2=max(0,maxDepth(root->right,pathsum,res));
        pathsum = r1+r2;
        res = max(res,pathsum + root->val);
        return (root->val + max(r1,r2));
    }
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        maxDepth(root,0,res);
        return res;
    }
};