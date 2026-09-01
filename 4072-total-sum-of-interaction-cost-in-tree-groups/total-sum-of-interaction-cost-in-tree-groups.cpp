class Solution {
public:
    vector<vector<long long>> indp;
    vector<vector<long long>> outdp;
    vector<int> ele;
    void f1(int node,int par,vector<vector<int>>&adj,vector<int>&grp,vector<vector<long long>> &sz,int grp_sz){
        
        sz[node][grp[node]] = 1;
        for(auto it : adj[node]) if(it != par){
            f1(it,node,adj,grp,sz,grp_sz);
            for(int i = 1;i<=grp_sz;i++){
                sz[node][i] += sz[it][i];
            }
            for(int i = 1;i<=grp_sz;i++){
                indp[node][i] += indp[it][i] + sz[it][i];
            }
        }
    }

    void f2(int node,int par,vector<vector<int>>&adj,vector<int>&grp,vector<vector<long long>> &sz,int grp_sz){
        for(auto it : adj[node])if(it != par){
            for(int i = 1;i<=grp_sz;i++){
                outdp[it][i] = outdp[node][i] + ele[i] - sz[it][i] + indp[node][i] - (indp[it][i] + sz[it][i]);
            }
            f2(it,node,adj,grp,sz,grp_sz);
        }
    }
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        vector<vector<int>> adj(n+1,vector<int>());
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int grp_sz = *max_element(group.begin(),group.end());
        vector<vector<long long>> sz(n+1,vector<long long>(grp_sz+1,0));
        ele.assign(grp_sz+1,0);
        for(int i = 0;i<n;i++){
            ele[group[i]] ++ ;
        }
        indp.assign(n+1,vector<long long>(grp_sz+1,0));
        outdp.assign(n+1,vector<long long>(grp_sz+1,0));

        f1(0,-1,adj,group,sz,grp_sz);
        f2(0,-1,adj,group,sz,grp_sz);
        long long ans = 0;
        for(int node = 0;node<n;node++){    
            
             ans += indp[node][group[node]] + outdp[node][group[node]];
            
        }
        return ans/2;
    }
};