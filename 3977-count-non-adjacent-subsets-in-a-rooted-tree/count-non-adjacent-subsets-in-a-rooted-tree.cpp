class Solution {
public:
    vector<vector<long long>> dp0;
    vector<vector<long long>> dp1;
    int MOD = 1e9+7;
    void f(int par,int node,vector<int>& nums,int k,vector<vector<int>>&adj){

        dp0[node][0] = 1;
        dp1[node][nums[node]%k] = 1;
       
        
        for(auto it : adj[node]){
            if(it == par) continue;

            f(node,it,nums,k,adj);
            vector<long long> na(k+1,0);
            vector<long long> nb(k+1,0);
            for(int i = 0;i<k;i++){
                for(int j = 0;j<k;j++){
                    int mod = (i+j)%k;

                    na[mod] = (na[mod] + (dp0[node][j]*((dp1[it][i] + dp0[it][i])%MOD))%MOD)%MOD ;
                    nb[mod] = (nb[mod] + (dp1[node][i]*dp0[it][j])%MOD)%MOD;
                }
            }
            dp0[node] = na;
            dp1[node] = nb;
        }
        
        
        // return cnt;
        
    }
    int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
        vector<vector<int>> adj(nums.size()+1,vector<int>());
        for(int i = 1;i<parent.size();i++){
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
        dp0.assign(nums.size()+1,vector<long long>(k+1,0));
        dp1.assign(nums.size()+1,vector<long long>(k+1,0));

        f(-1,0,nums,k,adj);
        return (int)(dp0[0][0] + dp1[0][0] -1)%MOD;
    }
};