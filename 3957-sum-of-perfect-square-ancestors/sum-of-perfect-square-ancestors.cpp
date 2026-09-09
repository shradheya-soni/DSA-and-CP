class Solution {
public:
    map<int,int> mpp;
    long long ans=  0;
    vector<vector<int>> adj;

    void f(int node,int par,vector<int>&nums){
        ans += mpp[nums[node]];
        mpp[nums[node]]++;
        for(auto it : adj[node])if(it != par){
            f(it,node,nums);
        }
        mpp[nums[node]]--;
    }

    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums){
        for(int i = 0;i<n;i++){
            for(int j = 318;j>=2;j--){
                int div = j*j;
                if(nums[i]%div == 0) nums[i]/=div;
            }
        }

        adj.assign(n+1,vector<int>());
        for(int i = 0;i<n-1;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }   
        
        f(0,-1,nums);
        return ans;
    }
};