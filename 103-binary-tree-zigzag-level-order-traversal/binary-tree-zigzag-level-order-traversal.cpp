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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // related with Level Order Traversal
        vector<vector<int>> res;
        if(root == NULL)
        return res;
        queue<TreeNode*>q;
        q.push(root);
        int check = 0; // 0 1 0 1 0 1 0 1
        // 0 -> forward
        // 1 -> reverse kro
        while(!q.empty()) {
            int n = q.size();
            vector<int> level;
            for(int i=0; i<n; i++) {
                TreeNode *ptr = q.front();
                q.pop();
                level.push_back(ptr->val);
                if(ptr->left != NULL)
                q.push(ptr->left);
                if(ptr->right != NULL)
                q.push(ptr->right);
            }
            if(check == 1) {
                reverse(level.begin(),level.end());
                check = 0;
            }
            else if(check == 0) {
                check = 1;
            }
            res.push_back(level);
        }
        return res;
    }
};