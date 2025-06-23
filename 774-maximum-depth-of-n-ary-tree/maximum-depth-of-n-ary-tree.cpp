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
    int maxDepth(Node* root) 
    {
        if(root==NULL)
        return 0;
        Node* ptr=root;
        int height=0;
        for(int i=0; i<ptr->children.size(); i++)
        {
            int resp=maxDepth(ptr->children[i]);
            height=max(resp,height);
        }
        return (height+1);
    }
};