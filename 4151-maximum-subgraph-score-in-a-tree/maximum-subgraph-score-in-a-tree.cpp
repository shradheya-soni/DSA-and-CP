class Solution {
public:
    vector<vector<int>> adj;
    vector<int> in;
    vector<int> out;
    void f1(int node,int par,vector<int>&arr){
        int val = arr[node];
        for(auto it : adj[node])if(it != par){
            f1(it,node,arr);
            val += max(0,in[it]);
        }
        in[node] = val;
    }
    void f(int node,int par,vector<int>&arr){
        for(auto it : adj[node])if(it != par){
            out[it] = max(0, out[node] + in[node] - max(0, in[it]) );
            f(it,node,arr);
        }
    }

    
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& arr) {
        for(int i = 0;i<n;i++){
            if(arr[i] == 0) arr[i] = -1;
        }
        adj.assign(n+1,vector<int>());
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        in.assign(n+1,0);
        out.assign(n+1,0);
        f1(0,-1,arr);
        f(0,-1,arr);
        vector<int> ans(n,0);
        for(int i = 0;i<n;i++){
            ans[i] = max(in[i],in[i]+out[i]);
        }
        return ans;
    }
        
};