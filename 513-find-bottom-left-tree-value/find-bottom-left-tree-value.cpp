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
    int leftmost = -1;
    int maxrow = -1;
    void dofindBottomLeftValue(TreeNode* root,int row) {
        if(root == NULL)
        return;
        dofindBottomLeftValue(root->left,row+1);
        dofindBottomLeftValue(root->right,row+1);
        if(maxrow == -1 || maxrow < row) {
            maxrow = row;
            leftmost = root->val;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        dofindBottomLeftValue(root,0);
        return leftmost;
    }
};