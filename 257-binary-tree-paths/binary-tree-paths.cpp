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
    void dfs(TreeNode* root, vector<string> &res, string str) {
        if(root == NULL)
        return;

        if(root->left || root->right)
        str = str + to_string(root->val) + "->";
        else {
            str += to_string(root->val);
            res.push_back(str);
            return;
        }
        dfs(root->left,res,str);
        dfs(root->right,res,str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string str = "";
        dfs(root,res,str);
        return res;
    }
};