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
    int maxDepth = 0;
    void dfs(TreeNode* root, unordered_map<TreeNode*,int> &mp, int level) {
        if(root == NULL) {
            maxDepth = max(maxDepth,level-1);
            return;
        }
        mp[root] = level;
        dfs(root->left,mp,level+1);
        dfs(root->right,mp,level+1);
    }
    TreeNode* lca(TreeNode* root, unordered_map<TreeNode*,int> &mp) {
        if(root == NULL) {
            return NULL;
        }
        if(mp[root] == maxDepth) {
            // deepest node is found
            return root;
        }
        TreeNode* left = lca(root->left,mp);
        TreeNode* right = lca(root->right,mp);
        if(left != NULL && right != NULL) {
            return root;
        }
        if(right != NULL && left == NULL) {
            return right;
        }
        if(left != NULL && right == NULL) {
            return left;
        }
        if(right == NULL && left == NULL) {
            return NULL;
        }
        return root;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // similar to lca
        // count the depth of each node
        unordered_map<TreeNode*,int> mp;
        dfs(root,mp,0);
        // now perform lca, and check that whether depth is equals to max depth
        return lca(root,mp);
    }
};