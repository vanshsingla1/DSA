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
    int maxSum = 0;

    //  {sum, isBST, min in region, max in region }
    vector<int> domaxSumBST(TreeNode* root) {
        if (root == NULL)
            return {0, 1, INT_MAX, INT_MIN};

        vector<int> l = domaxSumBST(root->left);
        vector<int> r = domaxSumBST(root->right);

        // If either subtree isn't a BST, we can't form one here
        if (!l[1] || !r[1])
            return {0, 0, 0, 0};

        // Full BST check using subtree min/max
        if (root->val <= l[3] || root->val >= r[2])
            return {0, 0, 0, 0};

        int sum = l[0] + r[0] + root->val;
        maxSum = max(maxSum, sum);

        // Compute new subtree min/max
        int subMin = root->left  ? l[2] : root->val;
        int subMax = root->right ? r[3] : root->val;
        return {sum, 1, subMin, subMax};
    }

    int maxSumBST(TreeNode* root) {
        domaxSumBST(root);
        return maxSum;
    }
};

