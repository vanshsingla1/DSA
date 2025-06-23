/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
        return NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            int count = n;
            for(int i=0; i<n; i++) {
                Node *ptr = q.front();
                q.pop();
                if(count == 1) {
                    //last node in a level, set its next value to NULL
                    ptr->next = NULL;
                }
                else {
                    count--;
                    //set its next to its right pointer
                    ptr->next = q.front();
                }
                if(ptr->left != NULL)
                q.push(ptr->left);
                if(ptr->right != NULL)
                q.push(ptr->right);
            }
        }
        return root;
    }
};