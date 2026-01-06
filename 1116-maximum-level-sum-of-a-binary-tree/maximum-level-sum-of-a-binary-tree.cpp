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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) {
            return -1;
        }
        queue<TreeNode*> q;
        int maxsum = INT_MIN;
        int level = 1;
        q.push(root);
        int currlevel = 1;
        while(!q.empty()) {
            int n = q.size();
            int sum = 0;
            for(int i=0; i<n; i++) {
                TreeNode *ptr = q.front();
                sum += ptr->val;
                q.pop();
                if(ptr->left != NULL) {
                    q.push(ptr->left);
                }
                if(ptr->right != NULL) {
                    q.push(ptr->right);
                }
            }
            if(maxsum < sum) {
                maxsum = sum;
                level = currlevel;
            }
            currlevel++;
        }
        return level;
    }
};