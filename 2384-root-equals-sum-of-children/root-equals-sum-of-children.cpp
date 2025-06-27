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
    bool checkTree(TreeNode* root) {
        if (root == nullptr)
            return false;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); 
            q.pop();
            int childSum = 0;
            if (node->left) {
                childSum += node->left->val;
                q.push(node->left);
            }
            if (node->right) {
                childSum += node->right->val;
                q.push(node->right);
            }
            if (node->left || node->right) {
                if (node->val != childSum)
                    return false;
            }
        }

        return true;
    }
};
