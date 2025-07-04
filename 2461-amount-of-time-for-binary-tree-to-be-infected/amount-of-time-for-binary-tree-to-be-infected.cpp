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
    void dfs(TreeNode* root,unordered_map<int,vector<int>> &adj) {
        if(root == NULL)
        return;
        if(root->left != NULL) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            dfs(root->left,adj);
        }
        if(root->right != NULL) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            dfs(root->right,adj);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        //convet tree into undirected graph and then traverse using BFS and find the max distance 
        unordered_map<int,vector<int>> adj;
        unordered_set<int>visited;
        // now traverse along the tree and update the values in adj list
        dfs(root,adj);
        //adj list is created , now traverse acc to BFS and find the max path
        queue<int>q;
        int maxPath = 0;
        visited.insert(start);
        q.push(start);
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                int node = q.front();
                q.pop();
                for(int neibhor : adj[node]) {
                    if(visited.find(neibhor) == visited.end()) {
                        q.push(neibhor);
                        visited.insert(neibhor);
                    }
                }
            }
            maxPath++;
        }
        return maxPath-1;
    }
};