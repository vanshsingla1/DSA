/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void preorder_traversal(Node* root,vector<int>&v)
    {
        if(root==NULL)
        return;
        stack<Node*>stk;
        stk.push(root);
        while(!stk.empty())
        {
            Node* ptr=stk.top();
            stk.pop();
            v.push_back(ptr->val);
            for(int i=ptr->children.size()-1; i>=0; i--)
            {
                stk.push(ptr->children[i]);
            }
        }
    }
    vector<int> preorder(Node* root) {
        vector<int>v;
        if(root==NULL)
        return v;
        preorder_traversal(root,v);
        return v;
    }
};