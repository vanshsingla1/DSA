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
    void insertinvector(TreeNode* root,vector<int>&v)
    {
        if(root==NULL)
        return;
        v.push_back(root->val);
        insertinvector(root->left,v);
        insertinvector(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
        return false;
        vector<int>v;
        insertinvector(root,v);
        for(int i=0; i<v.size(); i++)
        {
            for(int j=i+1; j<v.size(); j++)
            {
                if(v[i]+v[j]==k)
                return true;
            }
        }
        return false;
    }
};