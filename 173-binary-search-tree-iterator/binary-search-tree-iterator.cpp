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
class BSTIterator {
public:
    // inorder traversal
    int i = -1;
    vector<int> res;
    void inorder(TreeNode* root,vector<int> &res) {
        if(root == NULL)
        return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    BSTIterator(TreeNode* root) {
        // inorder traversal kro and store it in vector
        inorder(root,res);
        // Now the res is stored in vector
        i=0;
    }
    int next() {
        int nextt = res[i];
        i++;
        return nextt;
    }
    
    bool hasNext() {
        return (i<res.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */