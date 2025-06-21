/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
        return NULL;
       
        if(root->val==p->val || root->val==q->val)
        return root;
        TreeNode* r1 = lowestCommonAncestor(root->left,p,q);
        TreeNode* r2 = lowestCommonAncestor(root->right,p,q);
        if(r1!=NULL && r2!=NULL)
        return root;
        else if(r1!=NULL && r2==NULL)
        return r1;
        else if(r1==NULL && r2!=NULL)
        return r2;
        else
        return NULL;

    }
};