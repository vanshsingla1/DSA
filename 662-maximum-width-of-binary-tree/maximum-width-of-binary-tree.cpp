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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        queue<TreeNode*> q;
        queue<unsigned long long> idxQ;
        q.push(root);
        idxQ.push(0ULL);
        
        unsigned long long maxWidth = 0;
        
        while (!q.empty()) {
            int n = q.size();
            unsigned long long minLeft = ULLONG_MAX, maxRight = 0;
            
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front(); q.pop();
                unsigned long long idx = idxQ.front(); idxQ.pop();
                
                minLeft = min(minLeft, idx);
                maxRight = max(maxRight, idx);
                
                if (node->left) {
                    q.push(node->left);
                    idxQ.push(2*idx + 1);
                }
                if (node->right) {
                    q.push(node->right);
                    idxQ.push(2*idx + 2);
                }
            }
            
            maxWidth = max(maxWidth, maxRight - minLeft + 1);
        }
        
        return (int)maxWidth;
    }
};
