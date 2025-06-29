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
    vector<int> res;
    void dfs(TreeNode* root, int k) {
        if(root == NULL)
        return;
        if(k == 0) {
            res.push_back(root->val);
            return;
        }
        dfs(root->left,k-1);
        dfs(root->right,k-1);
    }
    int find(TreeNode* root, TreeNode* target, int k) {
        if(root == NULL)
        return -1;
        if(root == target) {
            dfs(root,k);
            return 1;
        }
        // now if target is not root itself then traverse to its left and right
        int l = find(root->left,target,k);
        if(l > 0) {
            dfs(root->right,k-l-1);
            if(l == k)
            res.push_back(root->val);
            return l+1;
        }

        int r = find(root->right,target,k);
        if(r > 0) {
            dfs(root->left,k-r-1);
            if(r == k)
            res.push_back(root->val);
            return r+1;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == NULL)
        return res; // empty vector
        //now find where is the target node
        find(root,target,k);
        return res;
    }
};