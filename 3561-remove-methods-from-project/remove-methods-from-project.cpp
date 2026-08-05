class Solution {
public:
    vector<int> mark;
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,set<int> &nodes){
        mark[node] = 1;
        nodes.insert(node);
        for(auto it : adj[node]){
            if(vis[it] != 1){
                vis[it] = 1;
                dfs(it,vis,adj,nodes);
            }
        }
    }
    bool dfs1(int node,vector<int>&vis,vector<vector<int>>&adj){
        if(mark[node] == 1) return false;
        bool var = true;
        for(auto it : adj[node]){
            if(vis[it] != 1){
                vis[it] = 1;
                var &= dfs1(it,vis,adj);
            }
        }
        return var;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n,vector<int>());
        for(int i = 0;i<invocations.size();i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        mark.assign(n+1,0);
        vector<int> vis(n,0);
        set<int> nodes;
        dfs(k,vis,adj,nodes);
        vis.assign(n,0);
        bool ans = true;
        for(int i = 0;i<n;i++){
            if(mark[i] == 0 && vis[i] != 1){
                ans &= dfs1(i,vis,adj);
            }
        }
        if(ans == false){
            vector<int> temp;
            for(int i = 0;i<n;i++) temp.push_back(i);
            return temp;
        }
        else{
            vector<int> temp;
            for(int i = 0;i<n;i++)if(nodes.find(i) == nodes.end()) temp.push_back(i);
            return temp;
        }
    }
};