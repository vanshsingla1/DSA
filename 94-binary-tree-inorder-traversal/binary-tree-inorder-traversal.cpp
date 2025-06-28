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
        //MORRIS TRAVERSAL
        vector<int> res;
        if(root == NULL)
        return res;
        TreeNode *ptr = root;
        while(ptr != NULL) {
            if(ptr->left == NULL) {
                res.push_back(ptr->val);
                ptr = ptr->right;
            }
            else {
                TreeNode *leftchild = ptr->left;
                while(leftchild->right != NULL)
                {
                    leftchild = leftchild->right;
                }
                leftchild->right = ptr;
                // now delete the connection b/w root and its left
                TreeNode *temp = ptr;
                ptr = ptr->left;
                temp->left = NULL;
            }
        }
        return res;
    }
};