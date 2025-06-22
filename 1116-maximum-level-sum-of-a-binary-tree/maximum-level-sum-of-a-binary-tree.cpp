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
    int levelOrder(TreeNode* root) {
        int level = 1;
        if(root == NULL)
        return -1;
        queue<TreeNode*>q;
        q.push(root);
        int maxsum = INT_MIN;
        int currlevel = 1;
        while(!q.empty()) {
            int n = q.size();
            int sum = 0;
            for(int i=0; i<n; i++) {
                TreeNode *ptr = q.front();
                q.pop();
                sum += ptr->val;
                if(ptr->left != NULL)
                q.push(ptr->left);
                if(ptr->right != NULL)
                q.push(ptr->right);
            }
            if(sum > maxsum) {
                maxsum = sum;
                level = currlevel;
            }
            currlevel++;
        }
        return level;
    }
    int maxLevelSum(TreeNode* root) {
        return levelOrder(root);
    }
};