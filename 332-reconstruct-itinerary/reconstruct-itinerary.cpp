class Solution {
public:
    void dfs(unordered_map<string,vector<pair<string,int>>> &adj,vector<string> &res,string src) {
        for(auto &p : adj[src]) {
            if(p.second > 0) {
                p.second--;
                dfs(adj,res,p.first);
            }
        }
        res.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Man always departs from JFK
        // source = JFK, If there are multiple valid itineraries, you should return the itinerary that has the
        // smallest lexical order when read as a single string.
        // kind of Hierholzer's algo
        unordered_map<string,vector<pair<string,int>>> adj;
        // pair<string,int> // string count
        vector<string> res;
        for(auto ticket : tickets) {
            string u = ticket[0];
            string v = ticket[1];
            adj[u].push_back({v,1});
        }
        // sort for lexicographical order
        for(auto &it : adj) {
            sort(it.second.begin(),it.second.end());
        } 
        // now perform dfs along with adj
        dfs(adj,res,"JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};