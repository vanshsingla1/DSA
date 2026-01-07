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
    long long maxproduct = 0;
    const int MOD = 1e9+7;
    int dfs(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int suml = dfs(root->left);
        int sumr = dfs(root->right);
        return (suml+sumr+root->val);
    }
    int fun(TreeNode* root,int totalSum) {
        if(root == NULL) {
            return 0;
        }
        int suml = 0;
        int sumr = 0;
        if(root->left != NULL) {
            suml = fun(root->left,totalSum);
        }
        if(root->right != NULL) {
            sumr = fun(root->right,totalSum);
        }
        int subtreesum = suml+sumr+root->val;
        maxproduct = max(maxproduct,1LL * subtreesum * (totalSum-subtreesum));
        return (suml+sumr+root->val);
    }
    int maxProduct(TreeNode* root) {
        // first calculate total sum
        // product = subtree sum * (totalsum-subtree sum)
        if(root == NULL) {
            return 0;
        }
        int totalSum = dfs(root);
        fun(root,totalSum);
        return maxproduct%MOD;
    }
};