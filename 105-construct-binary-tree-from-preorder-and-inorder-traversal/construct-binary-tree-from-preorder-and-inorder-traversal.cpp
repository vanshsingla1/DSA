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
    TreeNode* PREandIN(vector<int> &pre,int ps,int pe, vector<int> &in ,int is,int ie)
{
    if(is > ie) //dead end
        return NULL;

    int root_data = pre[ps];

    TreeNode *root = new TreeNode(root_data);

    int lps,lpe,lis,lie; //left indicies
    int rps,rpe,ris,rie; //right indices


    int mid;
    for(int j=is;j<=ie;j++)
    {
        if(in[j] ==  root_data)
        {
            mid = j;
            break;
        }
    }
//i==loc
    lps = ps + 1;
    lis = is;
    lie = mid - 1;
    ris = mid + 1;
    rie = ie;
    rpe = pe;
    lpe = lie - lis + lps;
    rps = lpe + 1;

    root->left = PREandIN(pre,lps,lpe,in,lis,lie);
    root->right = PREandIN(pre,rps,rpe,in,ris,rie);

    return root;
}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
       return PREandIN(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    
    }
};