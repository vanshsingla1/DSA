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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root == NULL)
        return res;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> level;
            for(int i=0; i<n; i++) {
                Node *ptr = q.front();
                q.pop();
                level.push_back(ptr->val);
                for(int i=0; i<ptr->children.size(); i++) {
                    if(ptr->children[i] != NULL)
                    q.push(ptr->children[i]);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};