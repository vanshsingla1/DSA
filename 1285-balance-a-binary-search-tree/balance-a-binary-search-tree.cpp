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
    TreeNode *append(vector<int> &res,int low,int high) {
        if(low > high) return NULL;
        int mid = (low + high)/2;
        TreeNode *root = new TreeNode(res[mid]);
        root->left = append(res,low,mid-1);
        root->right = append(res,mid+1,high);
        return root;
    }
    void inorder(TreeNode* root,vector<int> &res) {
        if(root == NULL) return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    TreeNode* balanceBST(TreeNode* root) {
        // perform inorder traversal and construct a bst using middle value as a root
        vector<int> res;
        inorder(root,res); // inorder traversal
        // now construct bst
        int n = res.size();
        int low = 0;
        int high = n-1;
        TreeNode *newroot = NULL;
        newroot = append(res,low,high);
        return newroot;
    }
};