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
    TreeNode* searchBST(TreeNode* root, int val) {
        // BFS
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* ptr = q.front();
            q.pop();

            if (ptr->val == val)
            return ptr;
            
            if (ptr->left != NULL) 
            q.push(ptr->left);
            if (ptr->right != NULL) 
            q.push(ptr->right);
        }
        return NULL;
    }
};