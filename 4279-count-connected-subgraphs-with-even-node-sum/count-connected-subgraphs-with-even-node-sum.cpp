class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> adj(n+1,0);
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][1]] |= (1<<edges[i][0]);
            adj[edges[i][0]] |= (1<<edges[i][1]);

        }
        int ans = 0;
        for(int mask = 1;mask<1<<n;mask++){
            int sum = 0;
            for(int i = 0;i<n;i++){
                if((1<<i)&mask){
                    sum += nums[i];
                }
            }
            if(sum%2 == 1) continue;

            int node = __builtin_ctz(mask);

            int vis = 1<<node;
            int q = 1<<node;

            while(q>0){
                int t = __builtin_ctz(q);
                q &= ~(1<<t);
                vis |= (1<<t);

                int nxt = mask & adj[t] & ~vis;
                q |= nxt;
                vis |= nxt;
            }
            if(vis == mask) ans ++;
        }
        
        return ans;
    }
};