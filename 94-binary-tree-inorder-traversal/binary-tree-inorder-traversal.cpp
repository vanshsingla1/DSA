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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
        return res;
        stack<TreeNode*> stk;
        TreeNode *ptr = root;
        while(!stk.empty() || ptr != NULL) {
            while(ptr) {
                stk.push(ptr);
                ptr = ptr->left;
            }
            // now left portion is traversed and push the top element into stack
            ptr = stk.top();
            stk.pop();
            res.push_back(ptr->val);
            ptr = ptr->right;
        }
        return res;
    }
};