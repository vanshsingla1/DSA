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
    void inorder(TreeNode* root, map<int, vector<pair<int, int>>> &mp, int col, int row) {
        if (root == NULL)
            return;
        
        inorder(root->left, mp, col - 1, row + 1);
        mp[col].push_back({row, root->val});  
        inorder(root->right, mp, col + 1, row + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        inorder(root, mp, 0, 0);  

        vector<vector<int>> res;

        for (auto& [col, vec] : mp) {
            // sort by row, then by value
            sort(vec.begin(), vec.end());
            vector<int> colVals;
            for (auto& [row, val] : vec)
                colVals.push_back(val);
            res.push_back(colVals);
        }

        return res;
    }
};
