class Solution {
public:

    int dfs(int node,int par,vector<map<int,int>>&adj,vector<int>&ans,vector<int>&arr){

        for(auto it : adj[node])if(it.first != par){
            arr[node] ^= dfs(it.first,node,adj,ans,arr);
        }
        if(arr[node] == 1 && par != -1){
            ans.push_back(adj[par][node]);
        }
        return arr[node];
    }

    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        vector<map<int,int>> adj(n+1);
        int cnt = 0;
        vector<int>ans;
        vector<int>arr(n+1,0);
        for(int i = 0;i<start.length();i++){
            if(start[i] != target[i]) arr[i] =1 , cnt++;
        }
        if(cnt%2 == 1) return {-1};

        for(int i = 0;i<n-1;i++){
            adj[edges[i][0]][edges[i][1]] = i;
            adj[edges[i][1]][edges[i][0]] = i;
        }

        dfs(0,-1,adj,ans,arr);
        sort(ans.begin(),ans.end());
        return ans;
    }
};